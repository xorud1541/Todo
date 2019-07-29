#pragma once
#include <QTreeWidget>
#include <QVector>

#include "TodoData.h"
class DoneTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	DoneTreeWidget(QWidget* parent);
	~DoneTreeWidget();

	void AddDoneItem(QVector<TodoData>& done);
	void LoadDoneData(const QVector<TodoData>& data);

private:
	QTreeWidgetItem* treeParent_;
};

