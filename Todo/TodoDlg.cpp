#include "TodoDlg.h"

#include <QFont>
#include <QCurSor>
#include <QScrollBar>
#include <QAction>
TodoDlg::TodoDlg(QWidget* parent)
	:QDialog(parent)
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
	QDialog::close();
}