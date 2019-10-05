#include "TodoDlg.h"

#include <QFont>
#include <QCurSor>
#include <QScrollBar>
#include <QAction>
#include <QMessageBox>

#include "DateManager.h"

TodoDlg::TodoDlg(QWidget* parent)
	: QDialog(parent)
	, calendar_(NULL)
	, isShowCalendar_(false)
{
	ui.setupUi(this);
	font_.setPointSize(fontSize);
	ui.detailEdit->setFont(font_);

	QAction* okAction = new QAction(this);
	okAction->setShortcut(Qt::CTRL + Qt::Key_Return);
	addAction(okAction);

	QAction* cancelAction = new QAction(this);
	cancelAction->setShortcut(Qt::CTRL + Qt::Key_W);
	addAction(cancelAction);
	
	connect(okAction, &QAction::triggered, this, &TodoDlg::OnOkAction);
	connect(ui.okBtn, &QPushButton::clicked, this, &TodoDlg::OnClickOkBtn);
	connect(cancelAction, &QAction::triggered, this, &TodoDlg::OnCancelAction);
	connect(ui.deadLineBtn, &QPushButton::clicked, this, &TodoDlg::OnClickDeadLineBtn);
}

TodoDlg::~TodoDlg()
{
}

void TodoDlg::OnClickOkBtn()
{
	QString title = ui.toDoEdit->text();
	QString detail = ui.detailEdit->toPlainText();

	if (!title.isEmpty())
	{
		title_ = title;
		detail_ = detail;

		QDialog::accept();
	}

	QDialog::close();
}

void TodoDlg::OnClickDeadLineBtn()
{
	if (calendar_)
	{
		if (isShowCalendar_)
		{
			calendar_->close();
			isShowCalendar_ = false;
		}
		else
		{
			calendar_->show();
			isShowCalendar_ = true;
		}
	}
	else
	{
		//초기 생성
		calendar_ = new QCalendarWidget(this);
		connect(calendar_, &QCalendarWidget::clicked, this, &TodoDlg::OnClickDeadLineDate);
		isShowCalendar_ = true;
		calendar_->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
		calendar_->show();
	}
}

void TodoDlg::OnClickDeadLineDate(const QDate& date)
{
	int year, month, day;
	year = date.year();
	month = date.month();
	day = date.day();

	deadLine_ = DateManager::GetInstance().GetTodoDateFormat(year, month, day);

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, QString::fromLocal8Bit("날짜 선택하기"), 
		QString::fromLocal8Bit("%0년 %1월 %2일 로 선택하시겠습니까?")
		.arg(year).arg(month).arg(day), 
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) 
	{
		calendar_->close();
		isShowCalendar_ = false;

		QString qDateStr = QString::fromLocal8Bit("%0년%1월%2일")
			.arg(year).arg(month).arg(day);

		ui.deadLineLabel->setText(qDateStr);
	}
}

void TodoDlg::SetTodoTitle(QString title)
{
	title_ = title;

	ui.toDoEdit->setText(title_);
}

void TodoDlg::SetTodoDetail(QString detail)
{
	detail_ = detail;

	ui.detailEdit->setText(detail_);
}

void TodoDlg::SetTodoDeadLine(QString date)
{
	deadLine_ = date;

	if (!date.isEmpty())
	{
		QDate qDate = DateManager::GetInstance().GetDateFromString(date);

		QString qDateStr = QString::fromLocal8Bit("%0년%1월%2일")
			.arg(qDate.year()).arg(qDate.month()).arg(qDate.day());

		ui.deadLineLabel->setText(qDateStr);
	}
}

void TodoDlg::SetTodoChecked(bool checked)
{
	isChecked_ = checked;
}

void TodoDlg::SetTodoStartTime(QString startTime)
{
	startTime_ = startTime;
}

void TodoDlg::SetDataFromTodoData(TodoData& data)
{
	SetTodoTitle(data.GetTitle());
	SetTodoDetail(data.GetDetail());
	SetTodoDeadLine(data.GetDeadLine());
	SetTodoChecked(data.IsChecked());
	SetTodoStartTime(data.GetStartTime());
}

TodoData TodoDlg::GetTodoDataFromTodoDlg()
{
	TodoData data;
	data.SetTitle(title_);
	data.SetDetail(detail_);
	data.SetDeadLine(deadLine_);
	data.SetChecked(isChecked_);
	data.SetStartTime(startTime_);

	return data;
}

void TodoDlg::resizeEvent(QResizeEvent* e)
{
	int height = this->height();
	int width = this->width();

	QRect centerW = ui.centerWidget->geometry();
	QRect okBtn = ui.okBtn->geometry();
	QRect edit = ui.detailEdit->geometry();

	ui.centerWidget->setFixedWidth(width);
	ui.centerWidget->setFixedHeight(height - centerW.top());

	ui.line->setFixedWidth(width - 20);
}

void TodoDlg::showEvent(QShowEvent* e)
{
	ui.detailEdit->verticalScrollBar()->setValue(ui.detailEdit->verticalScrollBar()->maximum());
	if (startTime_.isEmpty())
	{
		QDateTime date = QDateTime::currentDateTime();
		QTime startTime = date.time();
		startTime_ = QString::number(startTime.msecsSinceStartOfDay());
	}

	ui.detailEdit->SetStartTime(startTime_);
}

void TodoDlg::OnOkAction()
{
	this->OnClickOkBtn();
}

void TodoDlg::OnCancelAction()
{
	this->OnClickOkBtn();
}