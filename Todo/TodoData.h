#pragma once
#include <Qstring>

class TodoData
{
public:
	TodoData()
		:checked_(false)
	{
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

private:
	QString title_;
	QString detail_;
	QString date_;
	bool checked_;
};
