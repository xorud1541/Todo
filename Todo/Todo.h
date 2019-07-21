#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_Todo.h"
#include "TodoData.h"

class Todo : public QMainWindow
{
	Q_OBJECT

public:
	Todo(QWidget *parent = Q_NULLPTR);

	void OnClickAddBtn();
	void OnClickDoneBtn();

protected:
	void resizeEvent(QResizeEvent *e);
	void closeEvent(QCloseEvent *e);
	void showEvent(QShowEvent* e);



private:
	Ui::TodoClass ui;
};
