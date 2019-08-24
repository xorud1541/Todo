#include "DoneTreeWidget.h"
#include "DateManager.h"
#include "ProjectManager.h"
#include "Todo.h"
#include "TodoDlg.h"

#include <QFont>
#include <QKeyEvent>
#include <QMouseEvent>

DoneTreeWidget::DoneTreeWidget(QWidget* parent)
	:QTreeWidget(parent)
	, showDetailAction_("Show Detail", this)
{
	treeParent_ = NULL;

	connect(&showDetailAction_, &QAction::triggered,
		this, &DoneTreeWidget::OnShowDetailAction);

	contextMenu_.addAction(&showDetailAction_);
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
		QString date = QString::fromLocal8Bit("¿À´Ã");
		treeParent_ = new QTreeWidgetItem(this);
		font.setPointSize(13);
		treeParent_->setText(0, date);
		treeParent_->setFont(0, font);
		insertTopLevelItem(0, treeParent_);
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

void DoneTreeWidget::LoadDetailData(const QTreeWidgetItem& item)
{
	QString date = item.parent()->text(0);
	QString title = item.text(0);

	TodoData data;
	ProjectManager::GetInstance().Load_Done_Data(data, date, title);

	TodoDlg todoDlg;
	todoDlg.SetTodoTitle(data.GetTitle());
	todoDlg.SetTodoDetail(data.GetDetail());
	
	QList<QWidget *> widgets = todoDlg.findChildren<QWidget *>();
	foreach(QWidget* widget, widgets) {
		if (strcmp(widget->metaObject()->className(), "QTextEdit") == 0)
		{
			QTextEdit *t = static_cast<QTextEdit*>(widget);
			t->setReadOnly(true);
		}
		else if (strcmp(widget->metaObject()->className(), "QLineEdit") == 0)
		{
			QLineEdit* t = static_cast<QLineEdit*>(widget);
			t->setReadOnly(true);
		}
	}

	todoDlg.exec(); //ReadOnly
}

void DoneTreeWidget::OnShowDetailAction()
{
	QTreeWidgetItem *item = currentItem();
	if (item)
		LoadDetailData(*item);
}

void DoneTreeWidget::mouseReleaseEvent(QMouseEvent* e)
{
	QTreeWidget::mouseReleaseEvent(e);

	if (e->button() == Qt::RightButton)
	{
		ShowContextMenu(e->globalPos());
	}
}

void DoneTreeWidget::ShowContextMenu(const QPoint& globalPos)
{
	const QTreeWidgetItem* treeItem = reinterpret_cast<const QTreeWidgetItem*>(itemAt(mapFromGlobal(globalPos)));
	if (treeItem == nullptr || treeItem->isHidden())
		return;

	int selectedCount = selectedItems().count();
	if (selectedCount == 0)
		return;

	showDetailAction_.setEnabled(selectedCount == 1);

	contextMenu_.move(globalPos);
	contextMenu_.show();
}
