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
		QString date = doneData[0].GetDate();
		treeParent_ = new QTreeWidgetItem(this);
		font.setPointSize(13);
		treeParent_->setText(0, date);
		treeParent_->setFont(0, font);
		addTopLevelItem(treeParent_);
	}

	for (int i = 0; i < doneData.size(); i++)
	{
		TodoData data = doneData[i];
		QTreeWidgetItem* item = new QTreeWidgetItem(treeParent_);
		font.setPointSize(12);
		item->setFont(0, font);
		item->setText(0, data.GetTitle());
		treeParent_->addChild(item);
	}
}

void DoneTreeWidget::LoadDoneData(const QVector<TodoData>& data)
{
	QFont font;
	QTreeWidgetItem* parent = NULL;
	QString currentDate;
	for (int i = 0; i < data.size(); i++)
	{
		TodoData todoData = data[i];
		QString date = todoData.GetDate();
		QString done = todoData.GetTitle();
		QString detail = todoData.GetDetail();

		if (currentDate.isEmpty())
			currentDate = date;

		if (parent == NULL)
		{
			parent = new QTreeWidgetItem(this);
			font.setPointSize(13);
			parent->setText(0, currentDate);
			parent->setFont(0, font);
			addTopLevelItem(parent);

			QTreeWidgetItem* item = new QTreeWidgetItem(parent);
			font.setPointSize(12);
			item->setFont(0, font);
			item->setText(0, done);
			parent->addChild(item);
		}
		else
		{
			//부모가 있고 
			if (currentDate.compare(date, Qt::CaseInsensitive) == 0)
			{
				QTreeWidgetItem* item = new QTreeWidgetItem(parent);
				font.setPointSize(12);
				item->setFont(0, font);
				item->setText(0, done);
				parent->addChild(item);
			}
			else
			{
				currentDate = date;
				parent = new QTreeWidgetItem(this);
				font.setPointSize(13);
				parent->setText(0, currentDate);
				parent->setFont(0, font);
				addTopLevelItem(parent);

				QTreeWidgetItem* item = new QTreeWidgetItem(parent);
				font.setPointSize(12);
				item->setFont(0, font);
				item->setText(0, done);
				parent->addChild(item);
			}
		}
	}
}