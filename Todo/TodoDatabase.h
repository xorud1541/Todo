#pragma once
#include <QtSql/qsql.h>
#include <QObject>
class TodoDatabase : public QObject
{
	Q_OBJECT

public:
	TodoDatabase();
	~TodoDatabase();
};

