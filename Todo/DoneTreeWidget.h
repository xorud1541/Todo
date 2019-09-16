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

	void AddTodayDoneItem(QVector<TodoData>& done);
	void LoadDetailData(const QTreeWidgetItem& item);
	void LoadDoneData(const QVector<TodoData>& data);
	void OnShowDetailAction();
	void OnDbClickItem();
	void SetMostTopDate(QString date);
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
	void DeleteAllItems();
	QString GetTodayString();

private:
	QVector<TodoData> doneHistory_;
	QMenu contextMenu_;
	QAction showDetailAction_;
	int mode_;
	bool IsThereTodayDone_;
};

