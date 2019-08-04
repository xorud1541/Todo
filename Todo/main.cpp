#include "Todo.h"
#include "ProjectManager.h"

#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString appPath = a.applicationDirPath();
	ProjectManager::GetInstance().InitDB(appPath);

	Todo w;
	w.show();
	return a.exec();
}
