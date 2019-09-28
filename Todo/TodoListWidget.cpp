#include "TodoListWidget.h"
#include "ProjectManager.h"
#include "DateManager.h"

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
	showDetailAction_(QString::fromLocal8Bit("상세보기"), this),
	deleteAction_(QString::fromLocal8Bit("삭제"), this)
{
	font_.setPointSize(fontSize);
	
	connect(this, &QListWidget::itemDoubleClicked, this, &TodoListWidget::OnDbClickListItem);
	connect(this, &QListWidget::itemClicked, this, &TodoListWidget::OnClickedItem);

	//context menus
	connect(&showDetailAction_, &QAction::triggered, this, &TodoListWidget::OnShowDetailAction);
	connect(&deleteAction_, &QAction::triggered, this, &TodoListWidget::OnDeleteAction);

	contextMenu_.addAction(&showDetailAction_);
	contextMenu_.addAction(&deleteAction_);
}

TodoListWidget::~TodoListWidget()
{
	itemDataMap_.clear();
}

void TodoListWidget::SortTodoItems()
{
	QVector<QListWidgetItem*> dataVec;
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* item = this->item(i);
		TodoData data = itemDataMap_[item];

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
		if (itemDataMap_[item(i)].IsChecked())
		{
			TodoData data = itemDataMap_[item(i)];
			data.SetDate(dateMng.GetCurrentDate());
			doneData.push_back(data);
		}
	}
}

void TodoListWidget::DeleteDoneItem( )
{
	int i = 0;
	for (;i < count();)
	{
		if (itemDataMap_[item(i)].IsChecked())
		{
			itemDataMap_.remove(item(i));
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
		ShowCurrentItemDlg();
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
	deleteAction_.setEnabled(selectedCount == 1);

	contextMenu_.move(globalPos);
	contextMenu_.show();
}

void TodoListWidget::SetTodoData(QListWidgetItem* item, const TodoData& data)
{
	if (item)
	{
		TodoData& dstData = itemDataMap_[item];
		QString title = data.GetTitle(); //할 일
		QString detail = data.GetDetail(); //상세내용
		QString deadLine = data.GetDeadLine(); //마감
		bool checked = data.IsChecked();

		//취소선설정
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		item->setData(Qt::CheckStateRole, Qt::Checked);
		if (checked)
		{
			font_.setStrikeOut(true);
			item->setData(Qt::CheckStateRole, Qt::Checked);
		}
		else
		{
			font_.setStrikeOut(false);
			item->setData(Qt::CheckStateRole, Qt::Unchecked);
		}

		item->setFont(font_);

		//아이템 데이터들 세팅
		dstData.SetTitle(title); //할 일 
		dstData.SetDetail(detail); //상세 정보
		dstData.SetDeadLine(deadLine); //마감날짜
		dstData.SetChecked(checked); //체크여부

		//아이템 디자인
		// 1. 할 일 색깔
		SetItemTextFromDeadLine(item, deadLine);

		//화면에 보여줄 타이틀
		item->setText(title);
	}
}

void TodoListWidget::RefreshCurrentDate()
{
	// 날짜가 갱신이되면 데드라인을 갱신해주는 코드
	int cnt = count();
	for (int i = 0; i < cnt; i++)
	{
		QListWidgetItem* item = this->item(i);
		TodoData& data = itemDataMap_[item];
		SetItemTextFromDeadLine(item, data.GetDeadLine());
	}
}

void TodoListWidget::OnShowDetailAction()
{
	ShowCurrentItemDlg();
}

void TodoListWidget::ShowCurrentItemDlg()
{
	QListWidgetItem* item = currentItem();
	TodoData& data = itemDataMap_[item];

	TodoDlg todoDlg;
	todoDlg.SetDataFromTodoData(data);

	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData tempData = todoDlg.GetTodoDataFromTodoDlg();
		SetTodoData(item, tempData);
	}
}

void TodoListWidget::OnDeleteAction()
{
	QListWidgetItem* item = takeItem(currentRow());
	itemDataMap_.remove(item);
}

void TodoListWidget::AddTodo(TodoData& todo)
{
	QListWidgetItem* item = new QListWidgetItem(this);

	SetTodoData(item, todo);

	addItem(item);
	itemDataMap_.insert(item, todo);
}

void TodoListWidget::SetItemTextFromDeadLine(QListWidgetItem* item, const QString& deadLine)
{
	if (item && !deadLine.isEmpty())
	{
		QString currentDate = dateMng.GetCurrentDate();
		if (currentDate == deadLine)
		{
			item->setTextColor(QColor(216, 56, 29));
		}
		else
		{
			item->setTextColor(QColor(0, 0, 0));
		}
	}
}

void TodoListWidget::CloseWindow()
{
	QFile file(ProjectManager::GetInstance().GetTodoListPath());
	if (file.exists())
		file.remove();

	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* witem = item(i);
		TodoData data = itemDataMap_[witem];
		ProjectManager::GetInstance().SaveTodoList(data);
	}
}


void TodoListWidget::ShowWindow()
{
	QFile file(ProjectManager::GetInstance().GetTodoListPath());
	if (!file.exists()) return;
	
	if (!loadFile)
	{
		ProjectManager::GetInstance().LoadTodoList(this);
		loadFile = true;
	}
}

void TodoListWidget::OnDbClickListItem(QListWidgetItem* item)
{
	ShowCurrentItemDlg();
}

void TodoListWidget::OnClickedItem(QListWidgetItem* item)
{
	auto isChecked = item->data(Qt::CheckStateRole);
	if (isChecked == Qt::Checked)
	{
		OnCheckedBox(item);
	}
	else
	{
		OnUncheckedBox(item);
	}
}

void TodoListWidget::OnCheckedBox(QListWidgetItem* item)
{
	TodoData& data = itemDataMap_[item];
	data.SetChecked(true);
	font_.setStrikeOut(true);

	item->setFont(font_);
}

void TodoListWidget::OnUncheckedBox(QListWidgetItem* item)
{
	TodoData& data = itemDataMap_[item];
	data.SetChecked(false);
	font_.setStrikeOut(false);

	item->setFont(font_);
}