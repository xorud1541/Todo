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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TodoClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *AddBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TodoClass)
    {
        if (TodoClass->objectName().isEmpty())
            TodoClass->setObjectName(QStringLiteral("TodoClass"));
        TodoClass->resize(401, 312);
        centralWidget = new QWidget(TodoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 70, 381, 181));
        AddBtn = new QPushButton(centralWidget);
        AddBtn->setObjectName(QStringLiteral("AddBtn"));
        AddBtn->setGeometry(QRect(332, 10, 61, 41));
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
        TodoClass->setWindowTitle(QApplication::translate("TodoClass", "Todo", Q_NULLPTR));
        AddBtn->setText(QApplication::translate("TodoClass", "\354\266\224\352\260\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TodoClass: public Ui_TodoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
