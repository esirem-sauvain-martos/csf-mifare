/********************************************************************************
** Form generated from reading UI file 'mifaregui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIFAREGUI_H
#define UI_MIFAREGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MifareGUI
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLabel *LastnameLabel;
    QLabel *FirstnameLabel;
    QPushButton *refreshButton;
    QLabel *label_6;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *connectButton;
    QPushButton *enrolButton;
    QPushButton *formatButton;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *IncrementValueLabel;
    QVBoxLayout *verticalLayout_7;
    QPushButton *incrementButton;
    QPushButton *decrementButton;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_2;
    QGridLayout *gridLayout_3;
    QLineEdit *firstnameEdit;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lastnameEdit;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_10;
    QPushButton *writeButton;
    QTextEdit *logTextEdit;

    void setupUi(QMainWindow *MifareGUI)
    {
        if (MifareGUI->objectName().isEmpty())
            MifareGUI->setObjectName(QString::fromUtf8("MifareGUI"));
        MifareGUI->resize(670, 575);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MifareGUI->sizePolicy().hasHeightForWidth());
        MifareGUI->setSizePolicy(sizePolicy);
        MifareGUI->setMinimumSize(QSize(670, 575));
        MifareGUI->setMaximumSize(QSize(670, 575));
        centralWidget = new QWidget(MifareGUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(660, 575));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 641, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        LastnameLabel = new QLabel(horizontalLayoutWidget);
        LastnameLabel->setObjectName(QString::fromUtf8("LastnameLabel"));

        verticalLayout_3->addWidget(LastnameLabel);

        FirstnameLabel = new QLabel(horizontalLayoutWidget);
        FirstnameLabel->setObjectName(QString::fromUtf8("FirstnameLabel"));

        verticalLayout_3->addWidget(FirstnameLabel);

        refreshButton = new QPushButton(horizontalLayoutWidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        verticalLayout_3->addWidget(refreshButton);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setEnabled(true);
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        connectButton = new QPushButton(horizontalLayoutWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout_4->addWidget(connectButton);

        enrolButton = new QPushButton(horizontalLayoutWidget);
        enrolButton->setObjectName(QString::fromUtf8("enrolButton"));

        horizontalLayout_4->addWidget(enrolButton);

        formatButton = new QPushButton(horizontalLayoutWidget);
        formatButton->setObjectName(QString::fromUtf8("formatButton"));

        horizontalLayout_4->addWidget(formatButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_2);

        line_3 = new QFrame(horizontalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        IncrementValueLabel = new QLabel(horizontalLayoutWidget);
        IncrementValueLabel->setObjectName(QString::fromUtf8("IncrementValueLabel"));
        IncrementValueLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(IncrementValueLabel, 1, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        incrementButton = new QPushButton(horizontalLayoutWidget);
        incrementButton->setObjectName(QString::fromUtf8("incrementButton"));

        verticalLayout_7->addWidget(incrementButton);

        decrementButton = new QPushButton(horizontalLayoutWidget);
        decrementButton->setObjectName(QString::fromUtf8("decrementButton"));

        verticalLayout_7->addWidget(decrementButton);


        gridLayout_2->addLayout(verticalLayout_7, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_4, 2, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        firstnameEdit = new QLineEdit(horizontalLayoutWidget);
        firstnameEdit->setObjectName(QString::fromUtf8("firstnameEdit"));

        gridLayout_3->addWidget(firstnameEdit, 2, 1, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        gridLayout_3->addLayout(verticalLayout_9, 0, 2, 1, 1);

        lastnameEdit = new QLineEdit(horizontalLayoutWidget);
        lastnameEdit->setObjectName(QString::fromUtf8("lastnameEdit"));

        gridLayout_3->addWidget(lastnameEdit, 1, 1, 1, 1);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));

        gridLayout_3->addLayout(verticalLayout_10, 3, 0, 1, 1);

        writeButton = new QPushButton(horizontalLayoutWidget);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));

        gridLayout_3->addWidget(writeButton, 3, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);


        verticalLayout_4->addLayout(verticalLayout_5);


        horizontalLayout->addLayout(verticalLayout_4);

        logTextEdit = new QTextEdit(centralWidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setGeometry(QRect(10, 490, 641, 71));
        logTextEdit->setReadOnly(true);
        MifareGUI->setCentralWidget(centralWidget);

        retranslateUi(MifareGUI);

        QMetaObject::connectSlotsByName(MifareGUI);
    } // setupUi

    void retranslateUi(QMainWindow *MifareGUI)
    {
        MifareGUI->setWindowTitle(QApplication::translate("MifareGUI", "Mifare GUI", nullptr));
        label_8->setText(QApplication::translate("MifareGUI", "Informations personnelles", nullptr));
        LastnameLabel->setText(QApplication::translate("MifareGUI", "Nom :", nullptr));
        FirstnameLabel->setText(QApplication::translate("MifareGUI", "Pr\303\251nom :", nullptr));
        refreshButton->setText(QApplication::translate("MifareGUI", "Actualiser", nullptr));
        label_6->setText(QString());
        connectButton->setText(QApplication::translate("MifareGUI", "Connexion", nullptr));
        enrolButton->setText(QApplication::translate("MifareGUI", "Enr\303\264ler", nullptr));
        formatButton->setText(QApplication::translate("MifareGUI", "Formater", nullptr));
        IncrementValueLabel->setText(QApplication::translate("MifareGUI", "0", nullptr));
        incrementButton->setText(QApplication::translate("MifareGUI", "+", nullptr));
        decrementButton->setText(QApplication::translate("MifareGUI", "-", nullptr));
        label_4->setText(QApplication::translate("MifareGUI", "Nom :", nullptr));
        label_3->setText(QApplication::translate("MifareGUI", "Pr\303\251nom :", nullptr));
        writeButton->setText(QApplication::translate("MifareGUI", "Ecrire", nullptr));
        logTextEdit->setHtml(QApplication::translate("MifareGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">===== [ Log ] =====</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MifareGUI: public Ui_MifareGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIFAREGUI_H
