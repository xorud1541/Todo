#include "DateManager.h"


DateManager::DateManager(QObject* parent)
	:QObject(parent)
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
}

DateManager::~DateManager()
{
}

