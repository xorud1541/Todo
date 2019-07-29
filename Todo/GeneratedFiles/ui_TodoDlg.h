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
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QPushButton *deadLineBtn;

    void setupUi(QWidget *ToDoDlg)
    {
        if (ToDoDlg->objectName().isEmpty())
            ToDoDlg->setObjectName(QStringLiteral("ToDoDlg"));
        ToDoDlg->setWindowModality(Qt::ApplicationModal);
        ToDoDlg->resize(615, 317);
        QIcon icon;
        icon.addFile(QStringLiteral("image/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ToDoDlg->setWindowIcon(icon);
        toDoEdit = new QLineEdit(ToDoDlg);
        toDoEdit->setObjectName(QStringLiteral("toDoEdit"));
        toDoEdit->setGeometry(QRect(90, 20, 401, 31));
        toDoLabel = new QLabel(ToDoDlg);
        toDoLabel->setObjectName(QStringLiteral("toDoLabel"));
        toDoLabel->setGeometry(QRect(10, 24, 64, 21));
        toDoLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(ToDoDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 591, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        detailLabel = new QLabel(ToDoDlg);
        detailLabel->setObjectName(QStringLiteral("detailLabel"));
        detailLabel->setGeometry(QRect(10, 80, 64, 15));
        detailEdit = new QTextEdit(ToDoDlg);
        detailEdit->setObjectName(QStringLiteral("detailEdit"));
        detailEdit->setGeometry(QRect(10, 110, 481, 191));
        okBtn = new QPushButton(ToDoDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(510, 270, 91, 31));
        line_2 = new QFrame(ToDoDlg);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(510, 80, 91, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(ToDoDlg);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 0, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(ToDoDlg);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(510, 240, 91, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(ToDoDlg);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(490, 90, 20, 161));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(ToDoDlg);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(600, 90, 20, 161));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        deadLineBtn = new QPushButton(ToDoDlg);
        deadLineBtn->setObjectName(QStringLiteral("deadLineBtn"));
        deadLineBtn->setGeometry(QRect(510, 100, 93, 28));

        retranslateUi(ToDoDlg);

        QMetaObject::connectSlotsByName(ToDoDlg);
    } // setupUi

    void retranslateUi(QWidget *ToDoDlg)
    {
        ToDoDlg->setWindowTitle(QApplication::translate("ToDoDlg", "TODO", Q_NULLPTR));
        toDoLabel->setText(QApplication::translate("ToDoDlg", "\355\225\240 \354\235\274", Q_NULLPTR));
        detailLabel->setText(QApplication::translate("ToDoDlg", "\354\203\201\354\204\270\353\202\264\354\232\251", Q_NULLPTR));
        okBtn->setText(QApplication::translate("ToDoDlg", "\355\231\225\354\235\270", Q_NULLPTR));
        deadLineBtn->setText(QApplication::translate("ToDoDlg", "\353\202\240\354\247\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToDoDlg: public Ui_ToDoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODODLG_H
