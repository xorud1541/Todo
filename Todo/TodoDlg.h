#pragma once
#include <QDialog.h>
#include <QCalendarWidget>

#include "ui_TodoDlg.h"
#include "TodoData.h"
class TodoDlg : public QDialog
{
	Q_OBJECT

public:
	TodoDlg(QWidget* parent = Q_NULLPTR);
	~TodoDlg();

	void OnClickOkBtn();
	void OnClickDeadLineBtn();
	void OnClickDeadLineDate(const QDate& date);

	QString GetTodoTitle() { return title_; };
	void SetTodoTitle(QString title);

	QString GetTodoDetail() { return detail_; };
	void SetTodoDetail(QString detail);

	QString GetTodoDeadLine() { return deadLine_; };
	void SetTodoDeadLine(QString date);

	bool IsChecked() { return isChecked_; };
	void SetTodoChecked(bool checked);

	void SetDataFromTodoData(TodoData& data);
	TodoData GetTodoDataFromTodoDlg();

protected:
	void resizeEvent(QResizeEvent* e);
	void showEvent(QShowEvent* e);

private:
	void OnOkAction();
	void OnCancelAction();

private:
	enum
	{
		fontSize = 13
	};

	Ui::ToDoDlg ui;
	QFont font_;
	QString title_;
	QString detail_;
	QCalendarWidget* calendar_;
	bool isShowCalendar_;
	bool isChecked_;
	QString deadLine_;
};

