#pragma once

#include <QObject>
#include <QtSql/qsqldatabase.h>

#include "TodoData.h"
#include "TodoListWidget.h"
#include "DataAPI.h"

#ifdef _DEBUG
	#pragma comment(lib, "Qt5Sqld")
#endif 
	#pragma comment(lib, "Qt5Sql")

namespace DB
{
	const QString dbName = "ToDoDB";
	const QString dbDriver = "QSQLITE";
	const QString dbFile = "Todo.db";
}

class ProjectManager : public DataAPI
{
public:
	static ProjectManager& GetInstance()
	{
		if (instance == NULL)
			instance = new ProjectManager();
		return *instance;
	}

	bool SaveTodoList(TodoData& data);
	bool LoadTodoList(TodoListWidget* list);

	virtual API_RETURN Save_Done_Data(
		const QString& date,
		const QString& done,
		const QString& detail);

	virtual API_RETURN Load_Done_Data(
		QVector<TodoData>& data,
		bool hasDetail = false);

	void InitDB(const QString& path);
	void FinDB();
	bool CreateTable();
	
private:
	ProjectManager();
	virtual ~ProjectManager();

	static ProjectManager* instance;
	QSqlDatabase db_;
	QString appPath_;
};

