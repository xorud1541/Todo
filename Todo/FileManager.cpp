#include "FileManager.h"

#include <QFile>
#include <QDir>
#include <QUrl>
FileManager::FileManager()
	: root_("D:\\Todo")
{
	QDir root(root_);
	if (!root.exists())
	{
		root.mkdir(root_);
	}
}


FileManager::~FileManager()
{
}

bool FileManager::CopyFileToStorage(const QString& path, const QString &storageName)
{
	QFile origin(path);
	if (!origin.exists()) return false; //존재하지 않을 경우

	QString storagePath = QString("%0\\%1").arg(root_).arg(storageName);
	QDir copyDir(storagePath);
	if (!copyDir.exists())
	{
		if (!copyDir.mkdir(storagePath)) return false;
	}

	QFileInfo file(path);
	QString copyPath = QString("%0\\%1").arg(storagePath).arg(file.fileName());
	
	if (!origin.copy(copyPath)) return false;

	return true;
}
