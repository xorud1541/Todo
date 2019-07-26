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

		todoDlg.exec();
	}
}

void TodoListWidget::AddTodo(TodoData& todo)
{
	QListWidgetItem* item = new QListWidgetItem(this);

	QFont font;
	font.setPointSize(15);
	font.setStrikeOut(false);
	item->setText(todo.GetTitle());
	item->setFont(font);
	todo.SetChecked(false);

	//item data Ãß°¡
	addItem(item);
	dataMap.insert(item, todo);
}

void TodoListWidget::CloseWindow()
{
	QFile file("setting");
	if (file.exists())
		file.remove();

	ProjectManager manager;
	for (int i = 0; i < count(); i++)
	{
		QListWidgetItem* witem = item(i);
		TodoData data = dataMap[witem];
		manager.SaveTodoList(data);
	}
}


void TodoListWidget::ShowWindow()
{
	QFile file("setting");
	if (!file.exists()) return;
	
	if (!loadFile)
	{
		ProjectManager manager;
		manager.LoadTodoList(this);

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