# Todo
일정 관리를 위한 프로그램

## 개발환경
1. 개발툴 : Visual Studio 2017
2. 프레임워크 : Qt5(5.9.1)
3. OS : Windows 10

## 설치순서
- visual studio 설치
    - https://visualstudio.microsoft.com/ko/downloads/

- qt5 설치
    - https://download.qt.io/official_releases/qt/5.9/5.9.1/
    - qt-opensource-windows-x86-5.9.1.exe

- qt add-in 설치
    - http://download.qt.io/development_releases/vsaddin/
    - qt-vsaddin-msvc2017-2.3.2.vsix

## 추가될 기능
- 시작프로그램 설정하기
- TodoDlg에서 폰트변경되는 이슈
- 작업분류 카테고리 추가하기
- 검색에서 영문 대소구분 안하기

## 알려진 버그들
- 배포판에 트레이 아이콘 안생기는 이유

## Todo Setup 실행법
1. git clone https://github.com/xorud1541/Todo.git
2. go to Setup folder
3. run TODO Setup.exe

-------------------------------------------------------------------------

### 상세 프로젝트 소개

해당 프로젝트는 개인의 일정을 추가하고 수정, 삭제를 할 수 있으며
완료한 일에 대해서는 데이터베이스를 통해 저장 및 조회가 가능하다.

- 일정 관리앱 메인
![info_main_todo](/assets/info_main_todo.png)

- 일정 기록
![info_log_todo](/assets/info_log_todo.png)

- 완료한 일정 조회 및 검색
![info_done](/assets/info_done.png)
