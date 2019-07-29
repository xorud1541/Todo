#include "TodoDlg.h"

TodoDlg::TodoDlg(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.okBtn, &QPushButton::clicked, this, &TodoDlg::OnClickOkBtn);
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

