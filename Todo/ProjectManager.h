#pragma once

#include <QObject>
#include <QtSql/qsqldatabase.h>
#include <QtNetwork/QNetworkAccessManager.h>
#include <QtNetwork/QNetworkReply.h>
#include <QtNetwork/QNetworkRequest.h>

#include "TodoData.h"
#include "TodoListWidget.h"
#include "DataAPI.h"

#ifdef _DEBUG
	#pragma comment(lib, "Qt5Sqld")
    #pragma comment(lib, "Qt5Networkd")
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

	bool Initialize();

	bool InitDB();
	bool Login();
	void FinDB();

	void OnReply();

	QString GetTodoListPath() { return todoListPath_; };

	virtual API_RETURN Save_Done_Data(
		const QString& date,
		const QString& done,
		const QString& detail);

	virtual API_RETURN Load_Done_Data(
		QVector<TodoData>& data,
		bool hasDetail = false);

	virtual API_RETURN Load_Done_Data(
		TodoData& data,
		QString date,
		QString done);

private:
	enum INIT
	{
		LOGIN = 0,
		DB
	};

	ProjectManager();
	virtual ~ProjectManager();

	bool CreateTable();

	static ProjectManager* instance;
	QSqlDatabase db_;
	QString dbPath_;
	QString todoListPath_;
	QNetworkAccessManager* networkManager_;
};

