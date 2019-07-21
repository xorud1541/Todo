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
 
		ui.todoListWidget->AddTodo(data);
	}
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

void Todo::closeEvent(QCloseEvent* e)
{
	ui.todoListWidget->CloseWindow();
}

void Todo::showEvent(QShowEvent* e)
{
	ui.todoListWidget->ShowWindow();
}