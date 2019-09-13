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
#include <QCloseEvent>

Todo::Todo(QWidget *parent)
	: QMainWindow(parent)
	, trayShowAction_(QString::fromLocal8Bit("종료하기"), this)
{
	ui.setupUi(this);
	ui.doneBtn->setDisabled(false);

	dateTimer_ = new QTimer(this);
	dateTimer_->start(1000 * 60 * 60); //60분
	//dateTimer_->start(1000 * 60 * 1); //1분

	//date
	QString dateStr = QString("%0(%1)").arg(dateMng.GetDay()).arg(dateMng.GetWeek());
	ui.dateLabel->setText(dateStr);

	//done_data
	QVector<TodoData> dataFromDB;
	ProjectManager::GetInstance().Load_Done_Data(dataFromDB);
	ui.doneTreeWidget->LoadDoneHistory(dataFromDB);

	ui.tabWidget->setCurrentIndex(0);

	ui.searchEdit->setClearButtonEnabled(true);
#ifndef _DEBUG
	trayIcon_ = new QSystemTrayIcon(this);

	trayIconMenu_.addAction(&trayShowAction_);
	trayIcon_->setContextMenu(&trayIconMenu_);
	trayIcon_->setIcon(QIcon("./image/myIcon.ico"));
	trayIcon_->show();
#endif
	connect(ui.addBtn, &QPushButton::clicked, this, &Todo::OnClickAddBtn);
	connect(ui.doneBtn, &QPushButton::clicked, this, &Todo::OnClickDoneBtn);
	connect(ui.sortBtn, &QPushButton::clicked, this, &Todo::OnClickSortBtn);
	connect(ui.searchBtn, &QPushButton::clicked, this, &Todo::OnClickSearchBtn);
	connect(ui.searchEdit, &QLineEdit::textChanged, this, &Todo::OnClearSearchEdit);
	connect(ui.searchEdit, &QLineEdit::returnPressed, this, &Todo::OnClickSearchBtn);

	connect(trayIcon_, &QSystemTrayIcon::activated, this, &Todo::OnTrayIconClicked);
	connect(&trayShowAction_, &QAction::triggered, this, &Todo::OnClickTrayExit);

	connect(dateTimer_, &QTimer::timeout, this, &Todo::RefreshCurrentDate);
}

Todo::~Todo()
{
	ProjectManager::GetInstance().FinDB();
}

void Todo::OnClickTrayExit()
{
	trayIcon_->hide();
	trayIcon_ = NULL;

	this->close();
}

void Todo::OnTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Context: //메뉴
		trayIconMenu_.show();
		break;
	case QSystemTrayIcon::Trigger:
		this->show();
		break;
	}
}

void Todo::OnClickSearchBtn()
{
	QString search = ui.searchEdit->text();
	if (!search.isEmpty())
	{
		ui.doneTreeWidget->SearchText(search);
	}
}

void Todo::OnClearSearchEdit()
{
	if(ui.searchEdit->text().isEmpty())
		ui.doneTreeWidget->ReLoadDoneItems();
}

void Todo::RefreshCurrentDate()
{
	QString beforeUpdate = dateMng.GetCurrentDate();
	dateMng.UpdateCurrentDate();
	QString afterUpdate = dateMng.GetCurrentDate();

	if (beforeUpdate != afterUpdate)
	{
		ui.doneTreeWidget->SetMostTopDate(beforeUpdate);
	}

	QString dateStr = QString("%0(%1)").arg(dateMng.GetDay()).arg(dateMng.GetWeek());
	ui.dateLabel->setText(dateStr);
}

void Todo::OnClickAddBtn()
{
	TodoDlg todoDlg;
	if (todoDlg.exec() == QDialog::Accepted)
	{
		TodoData data(todoDlg);

		ui.todoListWidget->AddTodo(data);
	}
}

void Todo::OnClickDoneBtn()
{
	QVector<TodoData> doneData;
	ui.todoListWidget->GetDoneItem(doneData);

	if (!doneData.isEmpty())
	{
		ui.doneTreeWidget->AddTodayDoneItem(doneData);

		for (int i = 0; i < doneData.size(); i++)
		{
			if (!ProjectManager::GetInstance().Save_Done_Data(
				doneData[i].GetDate(),
				doneData[i].GetTitle(),
				doneData[i].GetDetail()) == API_RETURN::SUCCESS )
			{
				QMessageBox msgBox;
				msgBox.setText("Failed to Save Data");
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
			}
		}
	}

	ui.todoListWidget->DeleteDoneItem();
}

void Todo::OnClickSortBtn()
{
	ui.todoListWidget->SortTodoItems();
}

void Todo::resizeEvent(QResizeEvent *e)
{
	const int tabBottomMargin = 20;
	const int listBottomMargin = tabBottomMargin + 50;
	int height = this->height();
	int width = this->width();
	QRect listRect = ui.todoListWidget->geometry();
	QRect treeRect = ui.doneTreeWidget->geometry();
	QRect tabRect = ui.tabWidget->geometry();

	//탭 위젯 사이즈 조정
	ui.tabWidget->setFixedHeight(height - tabRect.top() - tabBottomMargin);
	ui.tabWidget->setFixedWidth(width);

	//todolist 사이즈 조정
	ui.todoListWidget->setFixedHeight(height - listRect.top() - listBottomMargin);
	ui.todoListWidget->setFixedWidth(width - 10);

	//donetree 사이즈 조정
	ui.doneTreeWidget->setFixedHeight(height - treeRect.top() - listBottomMargin);
	ui.doneTreeWidget->setFixedWidth(width - 10);

	ui.horizontalWidget->setFixedWidth(width - 10);
}

void Todo::closeEvent(QCloseEvent* e)
{
	if (trayIcon_)
	{
		this->hide();
		e->ignore();
	}
	else
	{
		ui.todoListWidget->CloseWindow();
	}
}

void Todo::showEvent(QShowEvent* e)
{
	ui.todoListWidget->ShowWindow();
}