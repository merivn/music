/********************************************************************************
** Form generated from reading UI file 'searchmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHMUSIC_H
#define UI_SEARCHMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchmusic
{
public:

    void setupUi(QWidget *searchmusic)
    {
        if (searchmusic->objectName().isEmpty())
            searchmusic->setObjectName(QStringLiteral("searchmusic"));
        searchmusic->resize(651, 448);

        retranslateUi(searchmusic);

        QMetaObject::connectSlotsByName(searchmusic);
    } // setupUi

    void retranslateUi(QWidget *searchmusic)
    {
        searchmusic->setWindowTitle(QApplication::translate("searchmusic", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class searchmusic: public Ui_searchmusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHMUSIC_H
