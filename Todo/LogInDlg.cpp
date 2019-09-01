#include "LogInDlg.h"

#include <QMessageBox>
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
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Incorrect Password");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}
}

void LogInDlg::OnClickLogIn()
{
	if (ui.pwEdit->text().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText("Input Password");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	pw_ = ui.pwEdit->text();

	QString request = QString("%0/users/%1").arg(HOST).arg(pw_);
	QUrl url(request);

	networkManager_->get(QNetworkRequest(url));
}
