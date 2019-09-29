#pragma once

#include <QTextEdit>

class DetailEdit : public QTextEdit
{
	Q_OBJECT

public:
	DetailEdit(QWidget* parent = Q_NULLPTR);
	~DetailEdit();

protected:
	void dropEvent(QDropEvent* e);
};

