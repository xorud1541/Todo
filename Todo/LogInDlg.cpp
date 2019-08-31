#include "LogInDlg.h"

LogInDlg::LogInDlg(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	networkManager_ = new QNetworkAccessManager(this);
	connect(ui.logInButton, &QPushButton::clicked, this, &LogInDlg::OnClickLogIn);
	connect(networkManager_, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
}

LogInDlg::~LogInDlg()
{
}

QString LogInDlg::GetID()
{
	return id_;
}

QString LogInDlg::GetPW()
{
	return pw_;
}

void LogInDlg::replyFinished(QNetworkReply *reply)
{
	int a = 5;
	qDebug() << "REQWE";
	QUrl url = reply->url();
	if (reply->error())
	{
		qDebug() << "Download of " << url.toEncoded().constData()
			<< " failed: " << reply->errorString();
	}
	else
	{
		QString path = url.path();

	}
}

void LogInDlg::OnClickLogIn()
{
	QString requ = QString("%0?id=%1&pw=%2")
		.arg(IPPORT)
		.arg("xorud1541")
		.arg("Secret091!");

	QUrl url("http://172.30.1.55:3000/");

	networkManager_->get(QNetworkRequest(url));
}
