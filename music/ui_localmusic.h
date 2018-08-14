/********************************************************************************
** Form generated from reading UI file 'localmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMUSIC_H
#define UI_LOCALMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_localmusic
{
public:
    QWidget *mainwidget;
    QPushButton *pushButton;

    void setupUi(QWidget *localmusic)
    {
        if (localmusic->objectName().isEmpty())
            localmusic->setObjectName(QStringLiteral("localmusic"));
        localmusic->resize(601, 452);
        mainwidget = new QWidget(localmusic);
        mainwidget->setObjectName(QStringLiteral("mainwidget"));
        mainwidget->setGeometry(QRect(10, 10, 571, 431));
        pushButton = new QPushButton(mainwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 200, 89, 27));

        retranslateUi(localmusic);

        QMetaObject::connectSlotsByName(localmusic);
    } // setupUi

    void retranslateUi(QWidget *localmusic)
    {
        localmusic->setWindowTitle(QApplication::translate("localmusic", "Form", 0));
        pushButton->setText(QApplication::translate("localmusic", "localmusic", 0));
    } // retranslateUi

};

namespace Ui {
    class localmusic: public Ui_localmusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMUSIC_H
