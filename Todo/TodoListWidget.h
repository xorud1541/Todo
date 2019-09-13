#pragma once
#include "TodoData.h"

#include <QListwidget>
#include <QMap>
#include <QVector>
#include <QMenu>
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
	void SetItemFromDeadLine(QListWidgetItem* item, const QString& deadLine);
	void CloseWindow();
	void ShowWindow();

	QMap<QListWidgetItem*, TodoData>& GetDataMap() { return dataMap_; };

	static bool loadFile;

protected:
	void keyPressEvent(QKeyEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

private:
	void ShowContextMenu(const QPoint& globalPos);
	void OnShowDetailAction();
	void OnDeleteAction();

private:
	enum
	{
		fontSize = 13
	};

	QMap<QListWidgetItem*, TodoData> dataMap_;
	QFont font_;
	QAction showDetailAction_;
	QAction deleteAction_;
	QMenu contextMenu_;
	int currentRow_;
};

