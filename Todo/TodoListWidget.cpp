#include "TodoListWidget.h"
#include "ProjectManager.h"

#include <QCheckbox>
#include <QVector>
#include <QFile>

TodoListWidget::TodoListWidget(QWidget* parent)
	:QListWidget(parent),
	checkedCnt_(0)
{

}

TodoListWidget::~TodoListWidget()
{
	dataMap.clear();
}



void TodoListWidget::DeleteDoneItem()
{
	int i = 0;
	for (;i < count();)
	{
		QCheckBox* chkBox = (QCheckBox*)itemWidget(item(i));
		if (chkBox->isChecked())
		{
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

void TodoListWidget::AddTodo(const TodoData& todo)
{
	QListWidgetItem* item = new QListWidgetItem(this);
	QCheckBox* chkBox = new QCheckBox(this);

	chkBox->setText(todo.GetTitle());

	//폰트 설정
	QFont font;
	font.setPointSize(15);
	chkBox->setFont(font);

	//style 변경
	chkBox->setStyleSheet("padding-left : 10px");
	item->setSizeHint(QSize(200, 30));

	//item data 추가
	setItemWidget(item, chkBox);
	dataMap.insert(item, todo);
	connect(chkBox, &QCheckBox::stateChanged, this, &TodoListWidget::OnClickListItem);
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
		
	ProjectManager manager;
	manager.LoadTodoList(this);
}

void TodoListWidget::OnClickListItem(int state)
{
	QCheckBox* chkBox = (QCheckBox*)sender();

	if (chkBox->checkState() == Qt::CheckState::Checked)
	{
		checkedCnt_++;
	}
	else
	{
		if (checkedCnt_ > 0)
		{
			checkedCnt_--;
		}
	}
}