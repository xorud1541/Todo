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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <TodoListWidget.h>

QT_BEGIN_NAMESPACE

class Ui_TodoClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    TodoListWidget *todoListWidget;
    QWidget *horizontalWidget;
    QHBoxLayout *buttonLayout;
    QLabel *dateLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *doneBtn;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TodoClass)
    {
        if (TodoClass->objectName().isEmpty())
            TodoClass->setObjectName(QStringLiteral("TodoClass"));
        TodoClass->resize(410, 837);
        centralWidget = new QWidget(TodoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -1, 411, 771));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        todoListWidget = new TodoListWidget(tab);
        todoListWidget->setObjectName(QStringLiteral("todoListWidget"));
        todoListWidget->setGeometry(QRect(0, 60, 401, 671));
        todoListWidget->setResizeMode(QListView::Adjust);
        horizontalWidget = new QWidget(tab);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(0, 10, 401, 41));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        buttonLayout = new QHBoxLayout(horizontalWidget);
        buttonLayout->setSpacing(0);
        buttonLayout->setContentsMargins(11, 11, 11, 11);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonLayout->setContentsMargins(5, 0, 0, 0);
        dateLabel = new QLabel(horizontalWidget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        dateLabel->setFont(font);

        buttonLayout->addWidget(dateLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        addBtn = new QPushButton(horizontalWidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        sizePolicy.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy);
        addBtn->setMinimumSize(QSize(0, 0));
        addBtn->setMaximumSize(QSize(70, 50));

        buttonLayout->addWidget(addBtn);

        doneBtn = new QPushButton(horizontalWidget);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));
        sizePolicy.setHeightForWidth(doneBtn->sizePolicy().hasHeightForWidth());
        doneBtn->setSizePolicy(sizePolicy);
        doneBtn->setMaximumSize(QSize(70, 50));

        buttonLayout->addWidget(doneBtn);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        TodoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TodoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 410, 26));
        TodoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TodoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TodoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TodoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TodoClass->setStatusBar(statusBar);

        retranslateUi(TodoClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TodoClass);
    } // setupUi

    void retranslateUi(QMainWindow *TodoClass)
    {
        TodoClass->setWindowTitle(QApplication::translate("TodoClass", "TODO", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("TodoClass", "\353\202\240\354\247\234(\354\232\224\354\235\274)", Q_NULLPTR));
        addBtn->setText(QApplication::translate("TodoClass", "\354\266\224\352\260\200", Q_NULLPTR));
        doneBtn->setText(QApplication::translate("TodoClass", "\354\231\204\353\243\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TodoClass", "\355\225\240 \354\235\274", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TodoClass", "\354\231\204\353\243\214\355\225\234 \354\235\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TodoClass: public Ui_TodoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
