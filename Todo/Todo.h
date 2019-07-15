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
	void OnClickListItem(int);

protected:
	void resizeEvent(QResizeEvent*);

private:
	void addTodo(TodoData);


private:
	Ui::TodoClass ui;
};
