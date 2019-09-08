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
	, showDetailAction_(QString::fromLocal8Bit("상세보기"), this)
	, mode_(MODE::SHOWLIST)
{
	treeParent_ = new QTreeWidgetItem(this);
	IsThereTodayDone_ = false;

	connect(&showDetailAction_, &QAction::triggered, this, &DoneTreeWidget::OnShowDetailAction);
	connect(this, &QTreeWidget::itemDoubleClicked, this, &DoneTreeWidget::OnDbClickItem);

	contextMenu_.addAction(&showDetailAction_);
}

DoneTreeWidget::~DoneTreeWidget()
{
}

void DoneTreeWidget::AddTodayDoneItem(QVector<TodoData>& doneData)
{
	QFont font;
	if (!IsThereTodayDone_  && mode_ == MODE::SHOWLIST)
	{
		QString date = QString::fromLocal8Bit("오늘");
		font.setPointSize(13);
		treeParent_->setText(0, date);
		treeParent_->setFont(0, font);
		insertTopLevelItem(0, treeParent_);
		IsThereTodayDone_ = true;
	}

	for (int i = 0; i < doneData.size(); i++)
	{
		TodoData data = doneData[i];
		doneHistory_.push_back(data);

		if (mode_ == MODE::SHOWLIST)
		{
			QTreeWidgetItem* item = new QTreeWidgetItem(treeParent_);
			font.setPointSize(12);
			item->setFont(0, font);
			item->setText(0, data.GetTitle());
			treeParent_->addChild(item);
		}
	}
}

void DoneTreeWidget::LoadDoneItems(const QVector<TodoData>& data)
{
	QFont font;
	QTreeWidgetItem* parent = NULL;
	QString currentDate;
	for (int i = 0; i < data.size(); i++)
	{
		TodoData todoData = data[i];
		QString date = todoData.GetDate(); //날짜
		QString done = todoData.GetTitle(); //한 일
		QString detail = todoData.GetDetail(); //상세내용

		if (date == dateMng.GetCurrentDate()) date = QString::fromLocal8Bit("오늘");

		if (currentDate.isEmpty()) currentDate = date;

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
			//한일이 현재 등록중인 날짜랑 같으면 
			if (currentDate.compare(date, Qt::CaseInsensitive) == 0)
			{
				QTreeWidgetItem* item = new QTreeWidgetItem(parent);
				font.setPointSize(12);
				item->setFont(0, font);
				item->setText(0, done);
				parent->addChild(item);
			}
			else //다른 날짜이면
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

void DoneTreeWidget::LoadDoneData(const QVector<TodoData>& data)
{
	LoadDoneItems(data);
	SetDoneHistroy(data);
}

void DoneTreeWidget::ShowDetailData(const QTreeWidgetItem& item)
{
	QString date = item.parent()->text(0);

	//"오늘" 이라는 날짜이면 현재날짜로 대체하는 코드  
	if (date == QString::fromLocal8Bit("오늘"))
		date = dateMng.GetCurrentDate();
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
		if(item->childCount() == 0)
			ShowDetailData(*item);
}

void DoneTreeWidget::OnDbClickItem()
{
	QTreeWidgetItem *item = currentItem();

	if (item)
		if (item->childCount() == 0)
			ShowDetailData(*item);
}

void DoneTreeWidget::RefreshTodayDate(QString date)
{
	QFont font;
	font.setPointSize(13);
	treeParent_->setText(0, date);
	treeParent_->setFont(0, font);

	IsThereTodayDone_ = false;
}

void DoneTreeWidget::SearchText(QString text)
{
	if (!text.isEmpty())
	{
		QVector<TodoData> searchData;
		int totalCount = doneHistory_.size();

		for (int i = 0; i < totalCount; i++)
		{
			TodoData data = doneHistory_[i];
			if (data.hasText(text))
			{
				searchData.push_back(data);
			}
		}

		DeleteAllItems();
		LoadDoneItems(searchData);
		mode_ = MODE::SEARCH;
	}
}
// 다시 원래 상태로 돌리는 코드
void DoneTreeWidget::ReLoadDoneItems()
{
	DeleteAllItems();
	mode_ = MODE::SHOWLIST;
	LoadDoneItems(doneHistory_);
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

void DoneTreeWidget::SetDoneHistroy(const QVector<TodoData>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		doneHistory_.push_back(data[i]);
	}
}

void DoneTreeWidget::DeleteAllItems()
{
	for (int i = 0; i < doneHistory_.size(); i++)
	{
		takeTopLevelItem(0);
	}
}
