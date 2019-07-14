#include "Todo.h"
#include "TodoDlg.h"

#include <QCheckbox>
#include <QFont>
Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::onClickAddBtn);
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

	QFont font;
	font.setPointSize(15);
	chkBox->setText(todo.title);
	chkBox->setFont(font);
	chkBox->setStyleSheet("padding-left : 10px");
	item->setSizeHint(QSize(50, 30));

	ui.listWidget->setItemWidget(item, chkBox);
}

void Todo::resizeEvent(QResizeEvent *e)
{
	const int bottomMargin = 50;
	int height = this->height();
	QRect listRect = ui.listWidget->geometry();
	ui.listWidget->setFixedHeight(height - listRect.top() - bottomMargin);
}