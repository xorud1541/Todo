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
		//�ʱ� ����
		calendar_ = new QCalendarWidget(this);
		connect(calendar_, &QCalendarWidget::clicked, this, &TodoDlg::OnClickDeadLineDate);
		isShowCalendar_ = true;
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
	reply = QMessageBox::question(this, QString::fromLocal8Bit("��¥ �����ϱ�"), 
		QString::fromLocal8Bit("%0�� %1�� %2�� �� �����Ͻðڽ��ϱ�?")
		.arg(year).arg(month).arg(day), 
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) 
	{
		calendar_->close();
		isShowCalendar_ = false;
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
}

void TodoDlg::OnOkAction()
{
	this->OnClickOkBtn();
}

void TodoDlg::OnCancelAction()
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