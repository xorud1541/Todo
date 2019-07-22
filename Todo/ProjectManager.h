#pragma once
#include <QObject>
#include "TodoData.h"
#include "TodoListWidget.h"
class ProjectManager : public QObject
{
	Q_OBJECT

public:
	ProjectManager();
	~ProjectManager();

	static bool SaveTodoList(TodoData& data);
	static bool LoadTodoList(TodoListWidget* list);
};

