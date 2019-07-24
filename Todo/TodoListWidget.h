#pragma once
#include "TodoData.h"

#include <QListwidget>
#include <QMap>
class TodoListWidget : public QListWidget
{
	Q_OBJECT

public:
	TodoListWidget(QWidget* parent);
	~TodoListWidget();

	int GetCheckedCnt() { return checkedCnt_;  };
	void SetCheckedCnt(int cnt) { checkedCnt_ = cnt;};

	void OnDbClickListItem(QListWidgetItem* item);

	void DeleteDoneItem();
	void AddTodo(TodoData& todo);
	void CloseWindow();
	void ShowWindow();

	QMap<QListWidgetItem*, TodoData>& GetDataMap() { return dataMap; };

	static bool loadFile;

private:
	QMap<QListWidgetItem*, TodoData> dataMap;
	QFont font_;
	int checkedCnt_;
};

