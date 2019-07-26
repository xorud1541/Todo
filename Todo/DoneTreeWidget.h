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

private:
	QTreeWidgetItem* treeParent_;
};

