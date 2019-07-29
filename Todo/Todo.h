#pragma once

#include <QtWidgets/QMainWindow>
#include <QDate>

#include "DateManager.h"
#include "ui_Todo.h"
#include "TodoData.h"

class Todo : public QMainWindow
{
	Q_OBJECT

public:
	Todo(QWidget *parent = Q_NULLPTR);
	~Todo();
	void OnClickAddBtn();
	void OnClickDoneBtn();
	void OnClickDoneTab(int index);

protected:
	void resizeEvent(QResizeEvent *e);
	void closeEvent(QCloseEvent *e);
	void showEvent(QShowEvent* e);

private:
	Ui::TodoClass ui;
	
	DateManager* dateMng;
};
