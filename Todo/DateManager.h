#pragma once
#include <QDate>
#include <QObject>

class DateManager : public QObject
{
	Q_OBJECT

public:
	static DateManager& GetInstance()
	{
		if (instance == NULL)
			instance = new DateManager();
		return *instance;
	}

	QString GetWeek() { return week_; };
	int GetDay() { return day_; };
	int GetYear() { return year_; };
	int GetMonth() { return month_; };

	void SetCurrentDate();
	QString GetCurrentDate();

private:
	DateManager();
	virtual ~DateManager();

	QString GetDayToStr();
	QString GetYearToStr();
	QString GetMonthToStr();

	QDate date_;
	QString week_;
	int day_;
	int year_;
	int month_;

	static DateManager* instance;
	QString currentDate_;
};

