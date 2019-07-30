#include "ProjectManager.h"
#include <QSettings>
#include <QFile>
#include <QDebug>

#include <QtSql/qsqlquery.h>

ProjectManager* ProjectManager::instance = nullptr;
bool ProjectManager::loadDB = false;

ProjectManager::ProjectManager()
{
}

ProjectManager::~ProjectManager()
{
}

void ProjectManager::InitDB()
{
	db_ = QSqlDatabase::addDatabase(DB::dbDriver);
	db_.setDatabaseName(DB::dbPath);

	if (!db_.open())
	{
		int a = 5; //추가예정
	}

	if (!CreateTable())
	{
		int b = 4; //추가예정
	}
}

void ProjectManager::FinDB()
{
	if (db_.isOpen())
		db_.close();

	QSqlDatabase::removeDatabase(DB::dbDriver);
}

bool ProjectManager::CreateTable()
{
	QStringList tables = db_.tables();
	QSqlQuery Sqlquery;
	bool ok;
	if (!tables.contains(DB::dbName))
	{
		const QString tableQuery = QString("CREATE TABLE %0 (%1 VARCHAR, %2 VARCHAR, %3 VARCHAR)")
			.arg(DB::dbName).arg("DATE").arg("DONE").arg("DETAIL");

		ok = Sqlquery.exec(tableQuery);
		if (!ok) return false;
	}

	return true;
}
bool ProjectManager::SaveTodoList(TodoData& data)
{
	QSettings settings("setting", QSettings::IniFormat);
	
	QString group = data.GetTitle();
	settings.beginGroup(group);
	settings.setValue("check", data.IsChecked());
	settings.setValue("detail", data.GetDetail());
	settings.endGroup();

	return true;
}

bool ProjectManager::LoadTodoList(TodoListWidget* list)
{
	QSettings settings("setting", QSettings::IniFormat);
	QStringList groups = settings.childGroups();

	for (const QString& group : groups)
	{
		settings.beginGroup(group);

		TodoData data;
		data.SetTitle(group);

		QStringList keys = settings.allKeys();

		for (const QString& key : keys)
		{
			if (key == "check")
			{
				QString value = settings.value(key).toString();
				if (value == "false")
					data.SetChecked(false);
				else
					data.SetChecked(true);
			}
			else if (key == "detail")
			{
				QString value = settings.value(key).toString();
				if (!value.isEmpty())
					data.SetDetail(value);
			}
		}
		keys.clear();
		list->AddTodo(data);

		settings.endGroup();
	}
	return true;
}

API_RETURN ProjectManager::Save_Done_Data(const QString& date,
	const QString& done, const QString& detail)
{
	const QString saveQuery = QString("insert or replace into %0 (%1, %2, %3) values (?, ?, ?)")
		.arg(DB::dbName).arg("DATE").arg("DONE").arg("DETAIL");

	db_.transaction();
	QSqlQuery query;
	
	if (!query.prepare(saveQuery))
		return API_RETURN::FAIL;

	query.bindValue(0, date);
	query.bindValue(1, done);
	query.bindValue(2, detail);

	if (!query.exec())
		return API_RETURN::FAIL;

	db_.commit();
	return API_RETURN::SUCCESS;
}

API_RETURN ProjectManager::Load_Done_Data(QVector<TodoData>& data, 
	bool hasDetail)
{
	const QString query = QString("SELECT %0, %1, %2 FROM %3")
		.arg("DATE").arg("DONE").arg("DETAIL").arg(DB::dbName);

	QSqlQuery selectQuery;
	if (!selectQuery.exec(query))
		return API_RETURN::FAIL;

	while (selectQuery.next())
	{
		TodoData dataFromDB;
		dataFromDB.SetDate(selectQuery.value(0).toString());
		dataFromDB.SetTitle(selectQuery.value(1).toString());

		if (hasDetail)
			dataFromDB.SetDetail(selectQuery.value(2).toString());

		data.push_back(dataFromDB);
	}

	loadDB = true;
	return API_RETURN::SUCCESS;
}