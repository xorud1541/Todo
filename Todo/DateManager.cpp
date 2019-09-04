#include "DateManager.h"

DateManager* DateManager::instance = nullptr;
DateManager::DateManager()
{
}

void DateManager::SetCurrentDate()
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

	currentDate_ = GetYearToStr() + GetMonthToStr() + GetDayToStr();
}

QString DateManager::GetCurrentDate()
{
	return currentDate_;
}

DateManager::~DateManager()
{
}

QString DateManager::GetDayToStr()
{
	if (day_ < 10)
		return QString("0%0").arg(day_);
	else
		return QString("%0").arg(day_);
}

QString DateManager::GetYearToStr()
{
	return QString("%0").arg(year_);
}

QString DateManager::GetMonthToStr()
{
	if (month_ < 10)
		return QString("0%0").arg(month_);
	else
		return QString("%0").arg(month_);
}