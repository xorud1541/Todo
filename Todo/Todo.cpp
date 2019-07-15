#include "Todo.h"
#include "TodoDlg.h"
#include "TodoListWidget.h"

#include <QCheckbox>
#include <QFont>
#include <QDatetime>

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(false);

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);

}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData data;

		data.SetTitle(todoDlg.getTodoTitle());
 
		addTodo(data);
	}
}

void Todo::addTodo(TodoData todo)
{
	QListWidgetItem* item = new QListWidgetItem(ui.todoListWidget);
	QCheckBox* chkBox = new QCheckBox(this);

	QFont font;
	font.setPointSize(15);
	chkBox->setText(todo.GetTitle());
	chkBox->setFont(font);
	chkBox->setStyleSheet("padding-left : 10px");
	item->setSizeHint(QSize(200, 30));

	//item data Ãß°¡
	ui.todoListWidget->setItemWidget(item, chkBox);
	connect(chkBox, &QCheckBox::stateChanged, ui.todoListWidget, &TodoListWidget::OnClickListItem);
}

void Todo::OnClickDoneBtn()
{
	ui.todoListWidget->DeleteDoneItem();
}

void Todo::resizeEvent(QResizeEvent *e)
{
	const int bottomMargin = 50;
	int height = this->height();
	QRect listRect = ui.todoListWidget->geometry();
	ui.todoListWidget->setFixedHeight(height - listRect.top() - bottomMargin);
}