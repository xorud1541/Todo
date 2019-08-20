#include "TodoDlg.h"

#include <QFont>
#include <QCurSor>
#include <QScrollBar>
TodoDlg::TodoDlg(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.okBtn, &QPushButton::clicked, this, &TodoDlg::OnClickOkBtn);

	QFont font;
	font.setPointSize(fontSize);
	ui.detailEdit->setFont(font);
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
	ui.centerWidget->setFixedHeight(height - centerW.top() );
}

void TodoDlg::showEvent(QShowEvent* e)
{
	ui.detailEdit->verticalScrollBar()->setValue(ui.detailEdit->verticalScrollBar()->maximum());
}