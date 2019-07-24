#include "Todo.h"
#include "TodoDlg.h"
#include "TodoListWidget.h"
#include "DateManager.h"

#include <QCheckbox>
#include <QFont>
#include <QDate>

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(false);

	DateManager date(this);
	QString dateStr = QString("%0(%1)").arg(date.GetDay()).arg(date.GetWeek());

	ui.dateLabel->setText(dateStr);

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);
}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData data;

		data.SetTitle(todoDlg.GetTodoTitle());
 
		ui.todoListWidget->AddTodo(data);
	}
}


void Todo::OnClickDoneBtn()
{
	ui.todoListWidget->DeleteDoneItem();
}

void Todo::resizeEvent(QResizeEvent *e)
{
	const int tabBottomMargin = 20;
	const int listBottomMargin = tabBottomMargin + 50;
	int height = this->height();
	int width = this->width();
	QRect listRect = ui.todoListWidget->geometry();
	QRect tabRect = ui.tabWidget->geometry();

	ui.tabWidget->setFixedHeight(height - tabRect.top() - tabBottomMargin);
	ui.tabWidget->setFixedWidth(width);

	ui.todoListWidget->setFixedHeight(height - listRect.top() - listBottomMargin);
	ui.todoListWidget->setFixedWidth(width - 10);

	ui.horizontalWidget->setFixedWidth(width - 10);
}

void Todo::closeEvent(QCloseEvent* e)
{
	ui.todoListWidget->CloseWindow();
}

void Todo::showEvent(QShowEvent* e)
{
	ui.todoListWidget->ShowWindow();
}