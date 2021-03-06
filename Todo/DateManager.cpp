#include "DateManager.h"

DateManager* DateManager::instance = nullptr;
DateManager::DateManager()
{
}

void DateManager::UpdateCurrentDate()
{
	date_ = QDate::currentDate();
	day_ = date_.day();
	year_ = date_.year();
	month_ = date_.month();

	int week = date_.dayOfWeek();
	switch (week)
	{
	case 1:
		week_ = QString::fromLocal8Bit("월");
		break;
	case 2:
		week_ = QString::fromLocal8Bit("화");
		break;
	case 3:
		week_ = QString::fromLocal8Bit("수");
		break;
	case 4:
		week_ = QString::fromLocal8Bit("목");
		break;
	case 5:
		week_ = QString::fromLocal8Bit("금");
		break;
	case 6:
		week_ = QString::fromLocal8Bit("토");
		break;
	case 7:
		week_ = QString::fromLocal8Bit("일");
		break;
	default:
		break;
	}

	currentDate_ = GetYearToStr(year_) + GetMonthToStr(month_) + GetDayToStr(day_);
}

void DateManager::InitDate()
{
	UpdateCurrentDate();
}

QString DateManager::GetCurrentDate()
{
	return currentDate_;
}

DateManager::~DateManager()
{
}

QString DateManager::GetDayToStr(int day)
{
	if (day < 10)
		return QString("0%0").arg(day);
	else
		return QString("%0").arg(day);
}

QString DateManager::GetYearToStr(int year)
{
	return QString("%0").arg(year);
}

QString DateManager::GetMonthToStr(int month)
{
	if (month < 10)
		return QString("0%0").arg(month);
	else
		return QString("%0").arg(month);
}

QString DateManager::GetTodoDateFormat(int year, int month, int day)
{
	QString date;
	if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
		return "";
	else
	{
		date = GetYearToStr(year) + GetMonthToStr(month) + GetDayToStr(day);
		return date;
	}
}

QDate DateManager::GetDateFromString(const QString& string)
{
	std::string stdString = string.toStdString();

	std::string yearStr = stdString.substr(0, 4);
	std::string monthStr = stdString.substr(4, 2);
	std::string dayStr = stdString.substr(6, 2);

	int year = atoi(yearStr.c_str());
	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());

	return QDate(year, month, day);
}