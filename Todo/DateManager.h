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

	void UpdateCurrentDate();
	QString GetCurrentDate();
	void InitDate();

	QString GetDayToStr(int day);
	QString GetYearToStr(int year);
	QString GetMonthToStr(int month);

	QString GetTodoDateFormat(int year, int month, int day);
	QDate GetDateFromString(const QString& string);

private:
	DateManager();
	virtual ~DateManager();

	QDate date_;
	QString week_;
	int day_;
	int year_;
	int month_;

	static DateManager* instance;
	QString currentDate_;
};

