#pragma once
#include <QDialog.h>
#include <QtNetwork/QNetworkAccessManager.h>
#include <QtNetwork/QNetworkReply.h>
#include <QtNetwork/QNetworkRequest.h>

#include "ui_TodoLogIn.h"
#ifdef _DEBUG
	#pragma comment(lib, "Qt5Networkd")
#else
#pragma comment(lib, "Qt5Network")
#endif // _DEBUG

const QString HOST = "http://211.184.106.214";
class LogInDlg : public QDialog
{
	Q_OBJECT

public:
	LogInDlg(QWidget* parent = Q_NULLPTR);
	~LogInDlg();

	QString GetID();
	QString GetPW();

	void OnClickLogIn();

public slots:
	void replyFinished(QNetworkReply *reply);
	

private:
	Ui::TodoLogIn ui;
	QString id_;
	QString pw_;

	QNetworkAccessManager* networkManager_;
};

