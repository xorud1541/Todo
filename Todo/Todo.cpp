#include "Todo.h"
#include "TodoDlg.h"

#include <QCheckbox>

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.AddBtn, &QPushButton::clicked, this, &Todo::onClickAddBtn);
}

void Todo::onClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		toDoData data;

		data.title = todoDlg.getTodoTitle();
 
		addTodo(data);
	}
}

void Todo::addTodo(toDoData todo)
{
	QListWidgetItem* item = new QListWidgetItem(ui.listWidget);
	QCheckBox* chkBox = new QCheckBox(this);
	chkBox->setText(todo.title);

	ui.listWidget->setItemWidget(item, chkBox);
}