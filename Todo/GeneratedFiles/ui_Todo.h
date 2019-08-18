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
#include "DoneTreeWidget.h"
#include "TodoListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_TodoClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *todoTab;
    TodoListWidget *todoListWidget;
    QWidget *horizontalWidget;
    QHBoxLayout *buttonLayout;
    QLabel *dateLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *addBtn;
    QPushButton *doneBtn;
    QPushButton *sortBtn;
    QWidget *doneTab;
    DoneTreeWidget *doneTreeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TodoClass)
    {
        if (TodoClass->objectName().isEmpty())
            TodoClass->setObjectName(QStringLiteral("TodoClass"));
        TodoClass->resize(462, 837);
        centralWidget = new QWidget(TodoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -1, 411, 751));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        todoTab = new QWidget();
        todoTab->setObjectName(QStringLiteral("todoTab"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(todoTab->sizePolicy().hasHeightForWidth());
        todoTab->setSizePolicy(sizePolicy);
        todoListWidget = new TodoListWidget(todoTab);
        todoListWidget->setObjectName(QStringLiteral("todoListWidget"));
        todoListWidget->setGeometry(QRect(0, 60, 401, 671));
        todoListWidget->setDragDropMode(QAbstractItemView::DragDrop);
        todoListWidget->setDefaultDropAction(Qt::MoveAction);
        todoListWidget->setProperty("isWrapping", QVariant(false));
        todoListWidget->setResizeMode(QListView::Adjust);
        todoListWidget->setWordWrap(false);
        todoListWidget->setSelectionRectVisible(true);
        todoListWidget->setSortingEnabled(false);
        horizontalWidget = new QWidget(todoTab);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(0, 10, 401, 41));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        buttonLayout = new QHBoxLayout(horizontalWidget);
        buttonLayout->setSpacing(4);
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
        addBtn->setMaximumSize(QSize(50, 40));
        addBtn->setAcceptDrops(false);
        addBtn->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral("image/add_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        addBtn->setIcon(icon);
        addBtn->setIconSize(QSize(50, 40));
        addBtn->setCheckable(false);
        addBtn->setFlat(true);

        buttonLayout->addWidget(addBtn);

        doneBtn = new QPushButton(horizontalWidget);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));
        sizePolicy.setHeightForWidth(doneBtn->sizePolicy().hasHeightForWidth());
        doneBtn->setSizePolicy(sizePolicy);
        doneBtn->setMaximumSize(QSize(50, 40));
        doneBtn->setAcceptDrops(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral("image/done_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        doneBtn->setIcon(icon1);
        doneBtn->setIconSize(QSize(37, 40));
        doneBtn->setCheckable(false);
        doneBtn->setAutoDefault(false);
        doneBtn->setFlat(true);

        buttonLayout->addWidget(doneBtn);

        sortBtn = new QPushButton(horizontalWidget);
        sortBtn->setObjectName(QStringLiteral("sortBtn"));
        sizePolicy.setHeightForWidth(sortBtn->sizePolicy().hasHeightForWidth());
        sortBtn->setSizePolicy(sizePolicy);
        sortBtn->setMinimumSize(QSize(0, 0));
        sortBtn->setMaximumSize(QSize(50, 40));
        sortBtn->setAcceptDrops(false);
        sortBtn->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral("image/sort_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        sortBtn->setIcon(icon2);
        sortBtn->setIconSize(QSize(50, 40));
        sortBtn->setCheckable(false);
        sortBtn->setFlat(true);

        buttonLayout->addWidget(sortBtn);

        tabWidget->addTab(todoTab, QString());
        doneTab = new QWidget();
        doneTab->setObjectName(QStringLiteral("doneTab"));
        doneTreeWidget = new DoneTreeWidget(doneTab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        doneTreeWidget->setHeaderItem(__qtreewidgetitem);
        doneTreeWidget->setObjectName(QStringLiteral("doneTreeWidget"));
        doneTreeWidget->setGeometry(QRect(0, 1, 401, 721));
        doneTreeWidget->setRootIsDecorated(true);
        doneTreeWidget->setUniformRowHeights(false);
        doneTreeWidget->setItemsExpandable(true);
        doneTreeWidget->setSortingEnabled(true);
        doneTreeWidget->setAnimated(false);
        doneTreeWidget->setAllColumnsShowFocus(false);
        doneTreeWidget->setWordWrap(false);
        doneTreeWidget->setHeaderHidden(true);
        doneTreeWidget->setColumnCount(1);
        doneTreeWidget->header()->setVisible(false);
        doneTreeWidget->header()->setCascadingSectionResizes(false);
        doneTreeWidget->header()->setHighlightSections(false);
        doneTreeWidget->header()->setProperty("showSortIndicator", QVariant(true));
        tabWidget->addTab(doneTab, QString());
        TodoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TodoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 462, 26));
        TodoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TodoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TodoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TodoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TodoClass->setStatusBar(statusBar);

        retranslateUi(TodoClass);

        tabWidget->setCurrentIndex(0);
        doneBtn->setDefault(false);


        QMetaObject::connectSlotsByName(TodoClass);
    } // setupUi

    void retranslateUi(QMainWindow *TodoClass)
    {
        TodoClass->setWindowTitle(QApplication::translate("TodoClass", "TODO", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("TodoClass", "\353\202\240\354\247\234(\354\232\224\354\235\274)", Q_NULLPTR));
        addBtn->setText(QString());
        doneBtn->setText(QString());
        sortBtn->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(todoTab), QApplication::translate("TodoClass", "\355\225\240 \354\235\274", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(doneTab), QApplication::translate("TodoClass", "\354\231\204\353\243\214\355\225\234 \354\235\274", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TodoClass: public Ui_TodoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
