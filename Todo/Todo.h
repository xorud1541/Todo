#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Todo.h"
typedef struct toDoData_
{
	QString title;
} toDoData;

class Todo : public QMainWindow
{
	Q_OBJECT

public:
	Todo(QWidget *parent = Q_NULLPTR);

	void onClickAddBtn();
private:

	void addTodo(toDoData);


private:
	Ui::TodoClass ui;
};
