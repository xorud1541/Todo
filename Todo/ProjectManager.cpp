#include "ProjectManager.h"
#include "LogInDlg.h"
#include "DateManager.h"

#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
#include <Qqueue>

ProjectManager* ProjectManager::instance = nullptr;

ProjectManager::ProjectManager()
{
}

ProjectManager::~ProjectManager()
{
}

bool ProjectManager::Initialize()
{
	QQueue<int> initQueue;
	//initQueue.push_back(INIT::LOGIN);
	initQueue.push_back(INIT::DB);
	initQueue.push_back(INIT::DATE);
	bool fail = false;
	
	while (!initQueue.empty())
	{
		int initOrder = initQueue.front();
		initQueue.pop_front();

		switch (initOrder)
		{
		case INIT::DB:
			if (!InitDB()) fail = true;
			break;
		case INIT::DATE:
			if(!InitDate()) fail = true;
			break;
		//case INIT::LOGIN:
		//	if(!Login()) fail = true;
		//	break;
		}

		if (fail) break;
	}

	if (fail) return false;
	else
		return true;
}

bool ProjectManager::Login()
{
	LogInDlg logInDlg;
	
	if (logInDlg.exec() == QDialog::Accepted)
	{
		return true;
	}
	else
		return false;
}

bool ProjectManager::InitDB()
{
	QString localPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);

	QDir localDir(localPath);
	if (!localDir.exists())
		localDir.mkdir(localPath);
	dbPath_ = localPath + QString("/%0").arg(DB::dbFile);
	todoListPath_ = localPath + "/TodoList";

	db_ = QSqlDatabase::addDatabase(DB::dbDriver);
	db_.setDatabaseName(dbPath_);

	if (!db_.open())
	{
		QMessageBox msgBox;
		msgBox.setText("Failed to open DB");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}

	if (!CreateTable())
	{
		QMessageBox msgBox;
		msgBox.setText("Failed to create DB");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}

	return true;
}

bool ProjectManager::InitDate()
{
	DateManager::GetInstance().UpdateCurrentDate();
	return true;
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
	QSettings settings(todoListPath_, QSettings::IniFormat);
	
	QString group = data.GetTitle();
	settings.beginGroup(group);
	settings.setValue("check", data.IsChecked());
	settings.setValue("detail", data.GetDetail());
	settings.setValue("deadline", data.GetDeadLine());
	settings.endGroup();

	return true;
}

bool ProjectManager::LoadTodoList(TodoListWidget* list)
{
	QSettings settings(todoListPath_, QSettings::IniFormat);
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
			else if (key == "deadline")
			{
				QString value = settings.value(key).toString();
				if (!value.isEmpty())
					data.SetDeadLine(value);
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

	return API_RETURN::SUCCESS;
}

API_RETURN ProjectManager::Load_Done_Data(TodoData& data, QString date,
	QString done)
{
	const QString query = QString("select * from %0 where DATE = \"%1\" and DONE = \"%2\"")
		.arg(DB::dbName).arg(date).arg(done);

	QSqlQuery selectQuery;
	if (!selectQuery.exec(query))
		return API_RETURN::FAIL;

	if (selectQuery.next())
	{
		data.SetTitle(selectQuery.value(1).toString());
		data.SetDetail(selectQuery.value(2).toString());
		return API_RETURN::SUCCESS;
	}
	else
	{
		return API_RETURN::FAIL;
	}
}