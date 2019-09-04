#include "Todo.h"
#include "ProjectManager.h"

#include <QtWidgets/QApplication>
#include <QSharedMemory>
#include <QMessageBox>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSharedMemory shared("TODO");
	if (!shared.create(512, QSharedMemory::ReadWrite))
	{
		QMessageBox msgBox;
		msgBox.setText("Already Running Program");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		exit(0);
	}

	if (ProjectManager::GetInstance().Initialize())
	{
		Todo w;
		w.show();
		return a.exec();
	}

	return 0;
}
