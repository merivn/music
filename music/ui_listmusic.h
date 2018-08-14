/********************************************************************************
** Form generated from reading UI file 'listmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTMUSIC_H
#define UI_LISTMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listmusic
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *listmusic)
    {
        if (listmusic->objectName().isEmpty())
            listmusic->setObjectName(QStringLiteral("listmusic"));
        listmusic->resize(437, 343);
        pushButton = new QPushButton(listmusic);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 160, 99, 27));

        retranslateUi(listmusic);

        QMetaObject::connectSlotsByName(listmusic);
    } // setupUi

    void retranslateUi(QWidget *listmusic)
    {
        listmusic->setWindowTitle(QApplication::translate("listmusic", "Form", 0));
        pushButton->setText(QApplication::translate("listmusic", "musiclist", 0));
    } // retranslateUi

};

namespace Ui {
    class listmusic: public Ui_listmusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTMUSIC_H
