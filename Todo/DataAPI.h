#pragma once
#include <QString>
#include <QVector>

#include "TodoData.h"

enum API_RETURN
{
	FAIL = 0,
	SUCCESS = 1
};

class DataAPI
{
public:
	DataAPI()
	{};
	virtual ~DataAPI()
	{};

	/*
	@ brief : �Ϸ��� ���� ������ �� ����� �Լ�
	@ name : Save_Done_Data
	@ para1 : date ( �Ϸ��� ��¥ yyyymmdd)
	@ para2 : done ( �Ϸ��� �� )
	@ para3 : detail ( �� ���� )
	@ return : API_RETURN
	*/
	
	virtual API_RETURN Save_Done_Data(
		const QString& date, 
		const QString& done, 
		const QString& detail) = 0;

	/*
	@ brief : Ư�� ��¥�� �ش��ϴ� �Ϸ��� ���� �������� �Լ�
	@ name : Load_Done_Date
	@ para1 : data ( �Ϸ��� �ϵ� )
	@ para2 : hasDetail ( �� ������ �����ϴ��� ���º��� )
	*/

	virtual API_RETURN Load_Done_Data(
		QVector<TodoData>& data,
		bool hasDetail = false
	) = 0;
};

