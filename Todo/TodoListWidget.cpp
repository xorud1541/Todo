#include "TodoListWidget.h"
#include "ProjectManager.h"
#include "TodoDlg.h"

#include <QCheckbox>
#include <QVector>
#include <QFile>
#include <QShortcut>
#include <QKeyEvent>

bool TodoListWidget::loadFile = false;

TodoListWidget::TodoListWidget(QWidget* parent)
	:QListWidget(parent),
	checkedCnt_(0)
{
	font_.setPointSize(15);
	
	connect(this, &QListWidget::itemDoubleClicked, this, &TodoListWidget::OnDbClickListItem);
}

TodoListWidget::~TodoListWidget()
{
	dataMap.clear();
}

void TodoListWidget::SortTodoItems()
{
	QVector<QListWidgetItem*> dataVec;
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* item = this->item(i);
		TodoData data = dataMap[item];

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

void TodoListWidget::DeleteDoneItem(QVector<TodoData>& doneData)
{
	int i = 0;
	for (;i < count();)
	{
		if (dataMap[item(i)].IsChecked())
		{
			doneData.push_back(dataMap[item(i)]);
			dataMap.remove(item(i));
			takeItem(i);

			i = 0;
			continue;
		}
		else
			i++;
	}

	checkedCnt_ = 0;
}

void TodoListWidget::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Return)
	{
		QListWidgetItem* item = currentItem();
		TodoData& data = dataMap[item];

		TodoDlg todoDlg;
		todoDlg.SetTodoTitle(data.GetTitle());
		todoDlg.SetTodoDetail(data.GetDetail());

		if (todoDlg.exec() == QDialog::Accepted)
		{
			data.SetTitle(todoDlg.GetTodoTitle());
			data.SetDetail(todoDlg.GetTodoDetail());
		}
	}
}

void TodoListWidget::AddTodo(TodoData& todo)
{
	QListWidgetItem* item = new QListWidgetItem(this);

	QFont font;
	font.setPointSize(15);

	item->setText(todo.GetTitle());
	
	if (todo.IsChecked())
		font.setStrikeOut(true);
	else
		font.setStrikeOut(false);
	item->setFont(font);

	//item data Ãß°¡
	addItem(item);
	dataMap.insert(item, todo);
}

void TodoListWidget::CloseWindow()
{
	QFile file("setting");
	if (file.exists())
		file.remove();

	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* witem = item(i);
		TodoData data = dataMap[witem];
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
	TodoData& data = dataMap[item];
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