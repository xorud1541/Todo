/********************************************************************************
** Form generated from reading UI file 'Todo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODO_H
#define UI_TODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <TodoListWidget.h>

QT_BEGIN_NAMESPACE

class Ui_TodoClass
{
public:
    QWidget *centralWidget;
    TodoListWidget *todoListWidget;
    QPushButton *addBtn;
    QPushButton *doneBtn;
    QLabel *dateLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TodoClass)
    {
        if (TodoClass->objectName().isEmpty())
            TodoClass->setObjectName(QStringLiteral("TodoClass"));
        TodoClass->resize(401, 406);
        centralWidget = new QWidget(TodoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        todoListWidget = new TodoListWidget(centralWidget);
        todoListWidget->setObjectName(QStringLiteral("todoListWidget"));
        todoListWidget->setGeometry(QRect(10, 70, 381, 181));
        addBtn = new QPushButton(centralWidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(260, 10, 61, 41));
        doneBtn = new QPushButton(centralWidget);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));
        doneBtn->setGeometry(QRect(330, 10, 61, 41));
        dateLabel = new QLabel(centralWidget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(20, 14, 181, 31));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        dateLabel->setFont(font);
        TodoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TodoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 26));
        TodoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TodoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TodoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TodoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TodoClass->setStatusBar(statusBar);

        retranslateUi(TodoClass);

        QMetaObject::connectSlotsByName(TodoClass);
    } // setupUi

    void retranslateUi(QMainWindow *TodoClass)
    {
        TodoClass->setWindowTitle(QApplication::translate("TodoClass", "TODO", Q_NULLPTR));
        addBtn->setText(QApplication::translate("TodoClass", "\354\266\224\352\260\200", Q_NULLPTR));
        doneBtn->setText(QApplication::translate("TodoClass", "\354\231\204\353\243\214", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("TodoClass", "\353\202\240\354\247\234(\354\232\224\354\235\274)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TodoClass: public Ui_TodoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
