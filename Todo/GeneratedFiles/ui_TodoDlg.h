/********************************************************************************
** Form generated from reading UI file 'TodoDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODODLG_H
#define UI_TODODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToDoDlg
{
public:
    QLineEdit *toDoEdit;
    QLabel *toDoLabel;
    QFrame *line;
    QLabel *detailLabel;
    QTextEdit *detailEdit;
    QPushButton *okBtn;

    void setupUi(QWidget *ToDoDlg)
    {
        if (ToDoDlg->objectName().isEmpty())
            ToDoDlg->setObjectName(QStringLiteral("ToDoDlg"));
        ToDoDlg->setWindowModality(Qt::ApplicationModal);
        ToDoDlg->resize(508, 317);
        toDoEdit = new QLineEdit(ToDoDlg);
        toDoEdit->setObjectName(QStringLiteral("toDoEdit"));
        toDoEdit->setGeometry(QRect(90, 20, 281, 31));
        toDoLabel = new QLabel(ToDoDlg);
        toDoLabel->setObjectName(QStringLiteral("toDoLabel"));
        toDoLabel->setGeometry(QRect(10, 24, 64, 21));
        toDoLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(ToDoDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 481, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        detailLabel = new QLabel(ToDoDlg);
        detailLabel->setObjectName(QStringLiteral("detailLabel"));
        detailLabel->setGeometry(QRect(10, 80, 64, 15));
        detailEdit = new QTextEdit(ToDoDlg);
        detailEdit->setObjectName(QStringLiteral("detailEdit"));
        detailEdit->setGeometry(QRect(10, 120, 361, 181));
        okBtn = new QPushButton(ToDoDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(390, 267, 101, 31));

        retranslateUi(ToDoDlg);

        QMetaObject::connectSlotsByName(ToDoDlg);
    } // setupUi

    void retranslateUi(QWidget *ToDoDlg)
    {
        ToDoDlg->setWindowTitle(QApplication::translate("ToDoDlg", "To-Do", Q_NULLPTR));
        toDoLabel->setText(QApplication::translate("ToDoDlg", "\355\225\240 \354\235\274", Q_NULLPTR));
        detailLabel->setText(QApplication::translate("ToDoDlg", "\354\203\201\354\204\270\353\202\264\354\232\251", Q_NULLPTR));
        okBtn->setText(QApplication::translate("ToDoDlg", "\355\231\225\354\235\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToDoDlg: public Ui_ToDoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODODLG_H
