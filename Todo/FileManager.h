#pragma once
#include <QObject>

class FileManager : public QObject
{
	Q_OBJECT

public:
	FileManager();
	~FileManager();

	bool CopyFileToStorage(const QString& path, const QString& storageName);

private:
	const QString storagePath_;
};

