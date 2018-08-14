/********************************************************************************
** Form generated from reading UI file 'mylrc.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLRC_H
#define UI_MYLRC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mylrc
{
public:

    void setupUi(QWidget *mylrc)
    {
        if (mylrc->objectName().isEmpty())
            mylrc->setObjectName(QStringLiteral("mylrc"));
        mylrc->resize(481, 370);

        retranslateUi(mylrc);

        QMetaObject::connectSlotsByName(mylrc);
    } // setupUi

    void retranslateUi(QWidget *mylrc)
    {
        mylrc->setWindowTitle(QApplication::translate("mylrc", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class mylrc: public Ui_mylrc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLRC_H
