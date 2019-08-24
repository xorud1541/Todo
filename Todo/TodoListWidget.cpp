#include "TodoListWidget.h"
#include "ProjectManager.h"
#include "DateManager.h"
#include "TodoDlg.h"

#include <QCheckbox>
#include <QVector>
#include <QFile>
#include <QShortcut>
#include <QKeyEvent>
#define dateMng		DateManager::GetInstance()
bool TodoListWidget::loadFile = false;

TodoListWidget::TodoListWidget(QWidget* parent)
	:QListWidget(parent), 
	currentRow_(-1),
	showDetailAction_(QString::fromLocal8Bit("상세보기"), this)
{
	font_.setPointSize(fontSize);
	
	connect(this, &QListWidget::itemDoubleClicked, this, &TodoListWidget::OnDbClickListItem);
	connect(&showDetailAction_, &QAction::triggered, this, &TodoListWidget::OnShowDetailAction);

	contextMenu_.addAction(&showDetailAction_);
}

TodoListWidget::~TodoListWidget()
{
	dataMap_.clear();
}

void TodoListWidget::SortTodoItems()
{
	QVector<QListWidgetItem*> dataVec;
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* item = this->item(i);
		TodoData data = dataMap_[item];

		if (data.IsChecked())
			dataVec.push_back(item);
		else
			dataVec.push_front(item);
	}

	for (int i = 0; i < dataVec.size(); i++)
		this->takeItem(0);
	
	for (int i = 0; i < dataVec.size(); i++)
	{
		QListWidgetItem* item = dataVec[i];
		this->addItem(item);
	}

}

void TodoListWidget::GetDoneItem(QVector<TodoData>& doneData)
{
	for (int i = 0; i < count(); i++)
	{
		if (dataMap_[item(i)].IsChecked())
		{
			TodoData data = dataMap_[item(i)];
			data.SetDate(dateMng.GetCurDate());
			doneData.push_back(data);
		}
	}
}

void TodoListWidget::DeleteDoneItem( )
{
	int i = 0;
	for (;i < count();)
	{
		if (dataMap_[item(i)].IsChecked())
		{
			dataMap_.remove(item(i));
			takeItem(i);

			i = 0;
			continue;
		}
		else
			i++;
	}
}

void TodoListWidget::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key_Return:
	{
		QListWidgetItem* item = currentItem();
		TodoData& data = dataMap_[item];

		TodoDlg todoDlg;
		todoDlg.SetTodoTitle(data.GetTitle());
		todoDlg.SetTodoDetail(data.GetDetail());

		if (todoDlg.exec() == QDialog::Accepted)
		{
			data.SetTitle(todoDlg.GetTodoTitle());
			data.SetDetail(todoDlg.GetTodoDetail());
			item->setText(todoDlg.GetTodoTitle());
		}
		break;
	}
	case Qt::Key_Up:
	{
		if (currentRow_ == -1)
		{
			currentRow_ = currentRow() - 1;
			setCurrentRow(currentRow_, QItemSelectionModel::SelectCurrent);
		}
		else if(currentRow_ == 0)
		{
			break;
		}
		else
		{
			currentRow_--;
			setCurrentRow(currentRow_, QItemSelectionModel::SelectCurrent);
		}
		break;
	}
	case Qt::Key_Down:
	{
		if (currentRow_ == -1)
		{
			currentRow_ = currentRow() + 1;
			setCurrentRow(currentRow_, QItemSelectionModel::SelectCurrent);
		}
		else if(currentRow_ == count() - 1)
		{
			break;
		}
		else
		{
			currentRow_++;
			setCurrentRow(currentRow_, QItemSelectionModel::SelectCurrent);
		}
		break;
	}
	default:
		break;
	}
}

void TodoListWidget::mouseReleaseEvent(QMouseEvent* e)
{
	QListWidget::mouseReleaseEvent(e);

	if (e->button() == Qt::RightButton)
	{
		ShowContextMenu(e->globalPos());
	}
}

void TodoListWidget::ShowContextMenu(const QPoint& globalPos)
{
	int selectedCount = selectedItems().size();
	if (selectedCount == 0) return;

	showDetailAction_.setEnabled(selectedCount == 1);

	contextMenu_.move(globalPos);
	contextMenu_.show();
}

void TodoListWidget::OnShowDetailAction()
{
	QListWidgetItem* item = currentItem();
	TodoData& data = dataMap_[item];

	TodoDlg todoDlg;
	todoDlg.SetTodoTitle(data.GetTitle());
	todoDlg.SetTodoDetail(data.GetDetail());

	if (todoDlg.exec() == QDialog::Accepted)
	{
		data.SetTitle(todoDlg.GetTodoTitle());
		data.SetDetail(todoDlg.GetTodoDetail());
		item->setText(todoDlg.GetTodoTitle());
	}
}

void TodoListWidget::AddTodo(TodoData& todo)
{
	QListWidgetItem* item = new QListWidgetItem(this);

	item->setText(todo.GetTitle());
	
	if (todo.IsChecked())
		font_.setStrikeOut(true);
	else
		font_.setStrikeOut(false);
	item->setFont(font_);

	//item data 추가
	addItem(item);
	dataMap_.insert(item, todo);
}

void TodoListWidget::CloseWindow()
{
	QFile file("setting");
	if (file.exists())
		file.remove();

	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* witem = item(i);
		TodoData data = dataMap_[witem];
		ProjectManager::GetInstance().SaveTodoList(data);
	}
}


void TodoListWidget::ShowWindow()
{
	QFile file("setting");
	if (!file.exists()) return;
	
	if (!loadFile)
	{
		ProjectManager::GetInstance().LoadTodoList(this);
		loadFile = true;
	}
}

void TodoListWidget::OnDbClickListItem(QListWidgetItem* item)
{
	TodoData& data = dataMap_[item];
	if (data.IsChecked())
	{
		font_.setStrikeOut(false);
		data.SetChecked(false);
	}
	else
	{
		font_.setStrikeOut(true);
		data.SetChecked(true);
	}

	item->setFont(font_);
}