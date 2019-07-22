#include "ProjectManager.h"

#include <QSettings>

ProjectManager::ProjectManager()
{
}


ProjectManager::~ProjectManager()
{
}

bool ProjectManager::SaveTodoList(TodoData& data)
{
	QSettings settings("setting", QSettings::IniFormat);
	
	QString group = data.GetTitle();
	settings.beginGroup(group);
	settings.setValue("check", data.IsChecked());
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
			if (key.compare("check", Qt::CaseInsensitive) == 0)
			{
				QString value = settings.value(key).toString();
				if (value == "false")
					data.SetChecked(false);
				else
					data.SetChecked(true);
			}
		}

		list->AddTodo(data);
	}
	return true;
}
