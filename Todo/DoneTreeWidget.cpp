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
	, IsThereTodayDone_(false)
{

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
	QTreeWidgetItem* parentDate = NULL;
	if (IsThereTodayDone_) // 이미 오늘 추가한 내용이 있을 경우(이미 날짜("오늘")는 등록된 상태 
	{
		if (mode_ == MODE::SHOWLIST)
		{
			parentDate = topLevelItem(0);
		}

		for (int i = 0; i < doneData.size(); i++)
		{
			TodoData data = doneData[i];
			doneHistory_.push_back(data);

			if (mode_ == MODE::SHOWLIST) //리스트를 보여줄때는 한일들 등록
			{
				QTreeWidgetItem* item = new QTreeWidgetItem(parentDate);
				font.setPointSize(12);
				item->setFont(0, font);
				item->setText(0, data.GetTitle());
				parentDate->addChild(item);
			}
		}
	}
	else // 오늘 처음 내용을 등록할 경우
	{
		if (mode_ == MODE::SHOWLIST) //날짜등록
		{
			QString date = GetTodayString();
			font.setPointSize(13);
			parentDate = new QTreeWidgetItem(this);
			parentDate->setText(0, date);
			parentDate->setFont(0, font);
			insertTopLevelItem(0, parentDate);
		}

		for (int i = 0; i < doneData.size(); i++)
		{
			TodoData data = doneData[i];
			doneHistory_.push_back(data);

			if (mode_ == MODE::SHOWLIST) //리스트를 보여줄때는 한일들 등록
			{
				QTreeWidgetItem* item = new QTreeWidgetItem(parentDate);
				font.setPointSize(12);
				item->setFont(0, font);
				item->setText(0, data.GetTitle());
				parentDate->addChild(item);
			}
		}
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

		if (date == dateMng.GetCurrentDate())
		{
			date = GetTodayString();
		}

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
			LoadDetailData(*item);
}

void DoneTreeWidget::OnDbClickItem()
{
	QTreeWidgetItem *item = currentItem();

	if (item)
		if (item->childCount() == 0)
			LoadDetailData(*item);
}

void DoneTreeWidget::SetMostTopDate(QString date)
{
	QTreeWidgetItem* topParent = topLevelItem(0);
	QFont font;
	font.setPointSize(13);
	topParent->setText(0, date);
	topParent->setFont(0, font);
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
		LoadDoneData(searchData);
		mode_ = MODE::SEARCH;
	}
}

void DoneTreeWidget::ReLoadDoneItems()
{
	DeleteAllItems();
	mode_ = MODE::SHOWLIST;
	LoadDoneData(doneHistory_);
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

QString DoneTreeWidget::GetTodayString()
{
	IsThereTodayDone_ = true;
	return QString::fromLocal8Bit("오늘");
}
