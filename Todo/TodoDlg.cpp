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
	//QString detail = ui.textEdit->toPlainText();

	if (!title.isEmpty())
	{
		title_ = title;

		QDialog::accept();
	}

	QDialog::close();
}


