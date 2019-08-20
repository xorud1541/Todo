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
	QString GetTodoTitle() { return title_; };
	void SetTodoTitle(QString title);

	QString GetTodoDetail() { return detail_; };
	void SetTodoDetail(QString detail);

	enum
	{
		fontSize = 13
	};

protected:
	void resizeEvent(QResizeEvent* e);
	void showEvent(QShowEvent* e);

private:
	Ui::ToDoDlg ui;

	QString title_;
	QString detail_;
};

