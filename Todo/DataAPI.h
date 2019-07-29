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
	@ brief : 완료한 일을 저장할 때 사용할 함수
	@ name : Save_Done_Data
	@ para1 : date ( 완료한 날짜 yyyymmdd)
	@ para2 : done ( 완료한 일 )
	@ para3 : detail ( 상세 내용 )
	@ return : API_RETURN
	*/
	
	virtual API_RETURN Save_Done_Data(
		const QString& date, 
		const QString& done, 
		const QString& detail) = 0;

	/*
	@ brief : 특정 날짜에 해당하는 완료한 일을 가져오는 함수
	@ name : Load_Done_Date
	@ para1 : data ( 완료한 일들 )
	@ para2 : hasDetail ( 상세 내용을 포함하는지 상태변수 )
	*/

	virtual API_RETURN Load_Done_Data(
		QVector<TodoData>& data,
		bool hasDetail = false
	) = 0;
};

