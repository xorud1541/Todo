#pragma once
#include <Qstring>
#include "TodoDlg.h"
class TodoData
{
public:
	TodoData()
		:checked_(false)
	{
	};

	TodoData(TodoDlg& dlg)
		:checked_(false)
	{
		title_ = dlg.GetTodoTitle();
		detail_ = dlg.GetTodoDetail();
		deadLine_ = dlg.GetTodoDeadLine();
	};

	~TodoData() {};

	QString GetTitle() const { return title_; };
	void SetTitle(QString title) { title_ = title; };

	bool IsChecked() { return checked_; };
	void SetChecked(bool checked) { checked_ = checked; };

	void SetDetail(QString detail) { detail_ = detail; };
	QString GetDetail() const { return detail_; };

	QString GetDate() const { return date_; };
	void SetDate(QString date) { date_ = date; };

	QDate GetDeadLine() const { return deadLine_; };
	void SetDeadLine(QDate deadLine) { deadLine_ = deadLine; };

	bool hasText(QString text)
	{
		if (title_.contains(text)) return true;

		if (detail_.contains(text)) return true;

		return false;
	}


private:
	QString title_;
	QString detail_;
	QString date_;
	QDate deadLine_;
	bool checked_;
};
