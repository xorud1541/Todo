#pragma once
#include <QDate>
#include <QObject>

class DateManager : public QObject
{
	Q_OBJECT

public:
	DateManager(QObject* parent = NULL);
	~DateManager();

	QString GetWeek() { return week_; };
	int GetDay() { return day_; };
	int GetYear() { return year_; };
	int GetMonth() { return month_; };
	QString GetDayToStr();
	QString GetYearToStr();
	QString GetMonthToStr();

	void SetCurDate(QString date) { currentDate_ = date; };
	QString GetCurDate() const { return currentDate_; };

private:
	QDate date_;
	QString week_;
	int day_;
	int year_;
	int month_;

	QString currentDate_;
};

