#pragma once
#include <QObject>

class FileManager : public QObject
{
	Q_OBJECT

public:
	FileManager();
	~FileManager();

	//storageName �� ���������� �����ϰ�, path�� �ִ� ������ ����ҿ� �����ϱ�
	bool CopyFileToStorage(const QString& path, const QString& storageName);

private:
	const QString root_;
};

