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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToDoDlg
{
public:
    QLineEdit *toDoEdit;
    QLabel *toDoLabel;
    QFrame *line;
    QWidget *centerWidget;
    QGridLayout *gridLayout;
    QLabel *detailLabel;
    QHBoxLayout *horizontalLayout;
    QTextEdit *detailEdit;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *deadLineLabel;
    QFrame *line_2;
    QPushButton *deadLineBtn;
    QFrame *line_4;
    QSpacerItem *verticalSpacer;
    QPushButton *okBtn;

    void setupUi(QWidget *ToDoDlg)
    {
        if (ToDoDlg->objectName().isEmpty())
            ToDoDlg->setObjectName(QStringLiteral("ToDoDlg"));
        ToDoDlg->setWindowModality(Qt::ApplicationModal);
        ToDoDlg->resize(594, 492);
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
        line->setGeometry(QRect(10, 60, 581, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(400, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        centerWidget = new QWidget(ToDoDlg);
        centerWidget->setObjectName(QStringLiteral("centerWidget"));
        centerWidget->setGeometry(QRect(10, 70, 581, 421));
        centerWidget->setMinimumSize(QSize(400, 300));
        gridLayout = new QGridLayout(centerWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        detailLabel = new QLabel(centerWidget);
        detailLabel->setObjectName(QStringLiteral("detailLabel"));

        gridLayout->addWidget(detailLabel, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        detailEdit = new QTextEdit(centerWidget);
        detailEdit->setObjectName(QStringLiteral("detailEdit"));

        horizontalLayout->addWidget(detailEdit);

        widget_2 = new QWidget(centerWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(100, 0));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        deadLineLabel = new QLabel(widget_2);
        deadLineLabel->setObjectName(QStringLiteral("deadLineLabel"));
        deadLineLabel->setMaximumSize(QSize(100, 30));

        verticalLayout_2->addWidget(deadLineLabel);

        line_2 = new QFrame(widget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        deadLineBtn = new QPushButton(widget_2);
        deadLineBtn->setObjectName(QStringLiteral("deadLineBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deadLineBtn->sizePolicy().hasHeightForWidth());
        deadLineBtn->setSizePolicy(sizePolicy2);
        deadLineBtn->setMinimumSize(QSize(0, 0));
        deadLineBtn->setMaximumSize(QSize(100, 30));
        deadLineBtn->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral("image/schedule_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        deadLineBtn->setIcon(icon1);
        deadLineBtn->setIconSize(QSize(50, 30));
        deadLineBtn->setFlat(true);

        verticalLayout_2->addWidget(deadLineBtn);

        line_4 = new QFrame(widget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        verticalSpacer = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer);

        okBtn = new QPushButton(widget_2);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        verticalLayout_2->addWidget(okBtn);


        horizontalLayout->addWidget(widget_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ToDoDlg);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(ToDoDlg);
    } // setupUi

    void retranslateUi(QWidget *ToDoDlg)
    {
        ToDoDlg->setWindowTitle(QApplication::translate("ToDoDlg", "TODO", Q_NULLPTR));
        toDoLabel->setText(QApplication::translate("ToDoDlg", "\355\225\240 \354\235\274", Q_NULLPTR));
        detailLabel->setText(QApplication::translate("ToDoDlg", "\354\203\201\354\204\270\353\202\264\354\232\251", Q_NULLPTR));
        deadLineLabel->setText(QString());
        deadLineBtn->setText(QString());
        okBtn->setText(QApplication::translate("ToDoDlg", "\355\231\225\354\235\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToDoDlg: public Ui_ToDoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODODLG_H
