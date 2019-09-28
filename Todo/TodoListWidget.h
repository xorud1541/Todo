#pragma once
#include "TodoData.h"
#include "TodoDlg.h"
#include <QMap>
#include <QVector>
#include <QMenu>
#include <QListWidget>

class QListWidgetItem;

class TodoListWidget : public QListWidget
{
	Q_OBJECT

public:
	TodoListWidget(QWidget* parent);
	~TodoListWidget();

	void DeleteDoneItem();
	void GetDoneItem(QVector<TodoData>& data);
	void SortTodoItems();
	void AddTodo(TodoData& todo);
	void SetItemTextFromDeadLine(QListWidgetItem* item, const QString& deadLine);
	void CloseWindow();
	void ShowWindow();

	/*
	* Function Name : SetTodoData
	* Parameters 
	* @para1 item : todolist에 넣을 아이템 인스턴스
	* @para2 data : item에 넣을 아이템 정보들
	*/
	void SetTodoData(QListWidgetItem* item, const TodoData& data);
	void RefreshCurrentDate();

	QMap<QListWidgetItem*, TodoData>& GetDataMap() { return dataMap_; };

	static bool loadFile;

protected:
	void keyPressEvent(QKeyEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

private:
	void ShowContextMenu(const QPoint& globalPos);
	void OnShowDetailAction();
	void ShowCurrentItemDlg();
	void OnDeleteAction();
	void OnDbClickListItem(QListWidgetItem* item);
	void OnClickedItem(QListWidgetItem* item);
	void OnCheckedBox(QListWidgetItem* item);
	void OnUncheckedBox(QListWidgetItem* item);

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

