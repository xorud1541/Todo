#include "Todo.h"
#include "TodoDlg.h"
#include "TodoListWidget.h"
#include "ProjectManager.h"
#include "DataAPI.h"
#include "DateManager.h"

#include <QCheckbox>
#include <QFont>
#include <QDate>
#include <QVector>
#include <QMessageBox>

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(false);
	QString dateStr = QString("%0(%1)").arg(dateMng.GetDay()).arg(dateMng.GetWeek());
	ui.dateLabel->setText(dateStr);

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);
	connect(ui.tabWidget, &QTabWidget::tabBarClicked, this, &Todo::OnClickDoneTab);

	QVector<TodoData> dataFromDB;
	ProjectManager::GetInstance().Load_Done_Data(dataFromDB);
	ui.doneTreeWidget->LoadDoneData(dataFromDB);
}

Todo::~Todo()
{
	ProjectManager::GetInstance().FinDB();
}

void Todo::OnClickDoneTab(int index)
{

}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData data;

		data.SetDate(dateMng.GetCurDate());
		data.SetTitle(todoDlg.GetTodoTitle());
		data.SetDetail(todoDlg.GetTodoDetail());

		ui.todoListWidget->AddTodo(data);
	}
}

void Todo::OnClickDoneBtn()
{
	QVector<TodoData> doneData;
	ui.todoListWidget->DeleteDoneItem(doneData);

	if (!doneData.isEmpty())
	{
		ui.doneTreeWidget->AddDoneItem(doneData);

		for (int i = 0; i < doneData.size(); i++)
		{
			if (ProjectManager::GetInstance().Save_Done_Data(
				doneData[i].GetDate(),
				doneData[i].GetTitle(),
				doneData[i].GetDetail()) == API_RETURN::SUCCESS )
			{
				//do Something
			}
		}
	}
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

	ui.doneTreeWidget->setFixedHeight(height - listRect.top() - listBottomMargin);
	ui.doneTreeWidget->setFixedWidth(width - 10);

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