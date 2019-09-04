#pragma once

#include <QtWidgets/QMainWindow>
#include <QDate>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer>

#include "DateManager.h"
#include "ui_Todo.h"
#include "TodoData.h"

#define dateMng		DateManager::GetInstance()
class Todo : public QMainWindow
{
	Q_OBJECT

public:
	Todo(QWidget *parent = Q_NULLPTR);
	~Todo();
	void OnClickAddBtn();
	void OnClickDoneBtn();
	void OnClickSortBtn();
	void OnClickTrayExit();

protected:
	void resizeEvent(QResizeEvent *e);
	void closeEvent(QCloseEvent *e);
	void showEvent(QShowEvent* e);

private:
	void OnTrayIconClicked(QSystemTrayIcon::ActivationReason);
	void RefreshCurrentDate();

private:
	Ui::TodoClass ui;

	QSystemTrayIcon* trayIcon_;
	QMenu trayIconMenu_;
	QAction trayShowAction_;
	QTimer* dateTimer_;
};
