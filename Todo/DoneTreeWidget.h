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
	void LoadDoneData(const QVector<TodoData>& data);
	void LoadDetailData(const QTreeWidgetItem& item);

	void OnShowDetailAction();
	void OnDbClickItem();
	void SetMostTopDate(QString date);

protected:
	void mouseReleaseEvent(QMouseEvent* e);

private:
	void ShowContextMenu(const QPoint& globalPos);

	bool IsThereTodayDone_;

private:
	QTreeWidgetItem* mostTopItem_;
	QMenu contextMenu_;
	QAction showDetailAction_;
};

