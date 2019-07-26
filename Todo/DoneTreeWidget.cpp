#include "DoneTreeWidget.h"
#include "DateManager.h"

#include <QFont>
DoneTreeWidget::DoneTreeWidget(QWidget* parent)
	:QTreeWidget(parent)
{
	treeParent_ = NULL;
}


DoneTreeWidget::~DoneTreeWidget()
{
	delete treeParent_;
}

void DoneTreeWidget::AddDoneItem(QVector<TodoData>& doneData)
{
	QFont font;
	if (treeParent_ == NULL)
	{
		DateManager date;
		int year = date.GetYear();
		int month = date.GetMonth();
		int day = date.GetDay();

		QString dataStr = QString("%0_%1_%2").arg(year).arg(month).arg(day);

		treeParent_ = new QTreeWidgetItem(this);
		font.setPointSize(13);
		treeParent_->setText(0, dataStr);
		treeParent_->setFont(0, font);
		addTopLevelItem(treeParent_);
	}

	for (int i = 0; i < doneData.size(); i++)
	{
		TodoData data = doneData[i];
		QTreeWidgetItem* item = new QTreeWidgetItem(treeParent_);
		font.setPointSize(10);
		item->setFont(0, font);
		item->setText(0, data.GetTitle());
		treeParent_->addChild(item);
	}
}