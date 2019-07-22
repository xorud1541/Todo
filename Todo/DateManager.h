#pragma once
#include <QDate>
#include <QObject>

class DateManager : public QObject
{
	Q_OBJECT

public:
	DateManager(QObject* parent);
	~DateManager();

	QString GetWeek() { return week_; };
	int GetDay() { return day_; };

private:
	QDate date_;
	QString week_;
	int day_;
};

