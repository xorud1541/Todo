#pragma once
#include "TodoData.h"

#include <QListwidget>
#include <QMap>
#include <QVector>

class TodoListWidget : public QListWidget
{
	Q_OBJECT

public:
	TodoListWidget(QWidget* parent);
	~TodoListWidget();

	void OnDbClickListItem(QListWidgetItem* item);

	void DeleteDoneItem();
	void GetDoneItem(QVector<TodoData>& data);
	void SortTodoItems();
	void AddTodo(TodoData& todo);
	void CloseWindow();
	void ShowWindow();

	QMap<QListWidgetItem*, TodoData>& GetDataMap() { return dataMap; };

	static bool loadFile;

	enum
	{
		fontSize = 13
	};

protected:
	void keyPressEvent(QKeyEvent* e);

private:
	QMap<QListWidgetItem*, TodoData> dataMap;
	QFont font_;

	int currentRow_;
};

