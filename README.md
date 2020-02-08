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

#### 프로젝트 UI
- 일정 관리앱 메인

![info_main_todo](/Todo/image/info_main_todo.png)
<br></br>
- 일정 기록

![info_log_todo](/Todo/image/info_log_todo.png)
<br></br>
- 완료한 일정 조회 및 검색

![info_done](/Todo/image/info_done.png)
<br><br>

#### 클래스 요약
- TodoListWidget

QListWidget 을 상속받은 클래스이며, 해야할 목록에 있는 Item들을 관리하는 클래스이다.

QMap을 사용하여 해당 리스트item 을 키값으로 하고, item에 대한 정보를 기억한다.
<br></br>
- TodoDlg

TodoListWidget의 Item의 상세정보들을 기록하기 위한 다이얼로그이다.
<br></br>
- DoneTreeWidget

완료한 일정을 보여주고 사용자가 특정 키워드를 입력할 시,

해당 키워드가 들어간 일정에 대해 조회가 가능하다.
<br></br>
- ProjectManager

앱에 필요한 정보들을 제공해주는 클래스이다.

주로 데이터베이스 or ini 파일 등 메타데이터들을 불러오기/저장을 관리하여

사용자 데이터를 안전하게 유지하는 역할을 한다.

(앱의 정보는 local경로에 위치한다.)
<br></br>
- LogInDlg

로그인 기능을 제공하는 클래스이다.

현재 기준으로 개발 중이며, 서버 작업이 완료되면 추가될 기능이다.
