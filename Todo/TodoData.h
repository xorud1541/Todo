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
private:
	QString title_;
	bool checked_;
};
