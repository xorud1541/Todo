#pragma once

#include <QTextEdit>

class DetailEdit : public QTextEdit
{
	Q_OBJECT

public:
	DetailEdit(QWidget* parent = Q_NULLPTR);
	~DetailEdit();

	void SetStartTime(QString startTime)
	{
		startTime_ = startTime;
	}

protected:
	void dropEvent(QDropEvent* e);

private:
	QString startTime_;
};

