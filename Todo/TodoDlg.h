#pragma once
#include <QDialog.h>

#include "ui_TodoDlg.h";

class TodoDlg : public QDialog
{
	Q_OBJECT

public:
	TodoDlg(QWidget* parent = Q_NULLPTR);
	~TodoDlg();

	void OnClickOkBtn();
	QString getTodoTitle();
private:
	Ui::ToDoDlg ui;

	QString title_;
	QString detail_;
};

