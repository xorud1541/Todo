#include "Todo.h"
#include "TodoDlg.h"
#include "TodoListWidget.h"
#include <QCheckbox>
#include <QFont>
Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(true);

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);
}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		toDoData data;

		data.title = todoDlg.getTodoTitle();
 
		addTodo(data);
	}
}

void Todo::OnClickListItem(int state)
{
	int checkedCnt = ui.todoListWidget->GetCheckedCnt();
	QCheckBox* chkBox = (QCheckBox*)sender();
	
	if (chkBox->checkState() == Qt::CheckState::Checked)
	{
		checkedCnt++;
		if (checkedCnt > 0) ui.doneBtn->setDisabled(false);
	}
	else
	{
		if (checkedCnt > 0)
		{
			checkedCnt--;
			if (checkedCnt == 0) ui.doneBtn->setDisabled(true);
		}
	}
	
	ui.todoListWidget->SetCheckedCnt(checkedCnt);
}
void Todo::addTodo(toDoData todo)
{
	QListWidgetItem* item = new QListWidgetItem(ui.todoListWidget);
	QCheckBox* chkBox = new QCheckBox(this);

	QFont font;
	font.setPointSize(15);
	chkBox->setText(todo.title);
	chkBox->setFont(font);
	chkBox->setStyleSheet("padding-left : 10px");
	item->setSizeHint(QSize(200, 30));

	ui.todoListWidget->setItemWidget(item, chkBox);

	connect(chkBox, &QCheckBox::stateChanged, this, &Todo::OnClickListItem);
}

void Todo::OnClickDoneBtn()
{
	
}

void Todo::resizeEvent(QResizeEvent *e)
{
	const int bottomMargin = 50;
	int height = this->height();
	QRect listRect = ui.todoListWidget->geometry();
	ui.todoListWidget->setFixedHeight(height - listRect.top() - bottomMargin);
}