#pragma once
#include <QObject>

class FileManager : public QObject
{
	Q_OBJECT

public:
	FileManager();
	~FileManager();

	bool CopyFileToStorage(const QString& path);

private:
	const QString storagePath_;
};

