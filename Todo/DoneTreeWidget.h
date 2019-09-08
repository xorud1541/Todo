#pragma once
#include <QTreeWidget>
#include <QVector>
#include <QMenu>
#include <QAction>
#include "TodoData.h"
class DoneTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	DoneTreeWidget(QWidget* parent);
	~DoneTreeWidget();

	void ShowDetailData(const QTreeWidgetItem& item);
	void AddTodayDoneItem(QVector<TodoData>& done);
	void LoadDoneData(const QVector<TodoData>& data);

	void OnShowDetailAction();
	void OnDbClickItem();
	void RefreshTodayDate(QString date);
	void SearchText(QString text);
	void ReLoadDoneItems();

	enum MODE
	{
		SHOWLIST = 0,
		SEARCH
	};

protected:
	void mouseReleaseEvent(QMouseEvent* e);

private:
	void ShowContextMenu(const QPoint& globalPos);
	void SetDoneHistroy(const QVector<TodoData>& data);
	void LoadDoneItems(const QVector<TodoData>& data);
	void DeleteAllItems();


	bool IsThereTodayDone_;

private:
	QVector<TodoData> doneHistory_;
	QTreeWidgetItem* treeParent_;
	QMenu contextMenu_;
	QAction showDetailAction_;
	int mode_;
};

