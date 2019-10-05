#pragma once
#include <QObject>

class FileManager : public QObject
{
	Q_OBJECT

public:
	FileManager();
	~FileManager();

	//storageName 을 폴더명으로 설정하고, path에 있는 파일을 저장소에 복사하기
	bool CopyFileToStorage(const QString& path, const QString& storageName);

private:
	const QString root_;
};

