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
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (status_code == 200)
	{
		QDialog::accept();
	}
}

void LogInDlg::OnClickLogIn()
{
	QUrl url("http://172.30.1.55:3000/users/Secret091!");

	networkManager_->get(QNetworkRequest(url));
}
