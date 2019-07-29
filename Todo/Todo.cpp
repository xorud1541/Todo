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

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(false);

	dateMng = new DateManager(this);
	QString dateStr = QString("%0(%1)").arg(dateMng->GetDay()).arg(dateMng->GetWeek());
	ui.dateLabel->setText(dateStr);

	//currentDate_ = dateMng->GetYearToStr() + dateMng->GetMonthToStr() + dateMng->GetDayToStr();

	dateMng->SetCurDate(dateMng->GetYearToStr() + dateMng->GetMonthToStr() + dateMng->GetDayToStr());

	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);
	connect(ui.tabWidget, &QTabWidget::tabBarClicked, this, &Todo::OnClickDoneTab);

	ProjectManager::GetInstance().InitDB();
}

Todo::~Todo()
{
	ProjectManager::GetInstance().FinDB();
}

void Todo::OnClickDoneTab(int index)
{
	if (index == 1)
	{
		if (!ProjectManager::GetInstance().loadDB)
		{
			QVector<TodoData> dataFromDB;
			ProjectManager::GetInstance().Load_Done_Data(dataFromDB);
			ui.doneTreeWidget->LoadDoneData(dataFromDB);
		}
	}

}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData data;

		data.SetDate(dateMng->GetCurDate());
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
		if(ProjectManager::GetInstance().loadDB)
			ui.doneTreeWidget->AddDoneItem(doneData);

		for (int i = 0; i < doneData.size(); i++)
		{
			TodoData data = doneData[i];
			QString date = data.GetDate();
			QString done = data.GetTitle();
			QString detail = data.GetDetail();
			if (ProjectManager::GetInstance().Save_Done_Data(date,
				done,
				detail) == API_RETURN::SUCCESS)
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