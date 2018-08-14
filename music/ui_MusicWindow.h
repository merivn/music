/********************************************************************************
** Form generated from reading UI file 'MusicWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QWidget *centralWidget;
    QWidget *bottomwidget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *premusicButton;
    QToolButton *playmusicButton;
    QToolButton *nextmusicButton;
    QLabel *palytimelabel_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *palytimelabel_2;
    QLabel *palytimelabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *lyriclabel;
    QSlider *playtimeSlider;
    QVBoxLayout *verticalLayout_4;
    QLabel *palytimetotallabel_2;
    QLabel *palytimetotallabel;
    QVBoxLayout *verticalLayout_5;
    QLabel *blanklabel3;
    QToolButton *volumeButton;
    QVBoxLayout *verticalLayout_6;
    QLabel *blanklabel4;
    QSlider *volumeSlider;
    QVBoxLayout *verticalLayout_7;
    QLabel *blanklabel3_2;
    QToolButton *playmodeButton;
    QVBoxLayout *verticalLayout_8;
    QLabel *blanklabel3_3;
    QToolButton *winlrcButton;
    QWidget *midwidget;
    QWidget *listwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *recommendlabel;
    QPushButton *foundmusicButton;
    QPushButton *privateFMButton;
    QPushButton *videoButton;
    QPushButton *friendButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *mymusiclabel;
    QPushButton *locmusicButton;
    QPushButton *downloadButton;
    QPushButton *mymusicButton;
    QPushButton *myradioButton;
    QPushButton *myenshrineButton;
    QSpacerItem *verticalSpacer;
    QScrollBar *listScrollBar;
    QWidget *contentwidget;
    QWidget *titlewidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *logoButton;
    QPushButton *TitleButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *minButton;
    QToolButton *maxButton;
    QToolButton *closeButton;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName(QStringLiteral("MusicWindow"));
        MusicWindow->resize(924, 625);
        QFont font;
        font.setFamily(QStringLiteral("URW Chancery L"));
        font.setItalic(true);
        MusicWindow->setFont(font);
        MusicWindow->setWindowTitle(QStringLiteral(""));
        centralWidget = new QWidget(MusicWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bottomwidget = new QWidget(centralWidget);
        bottomwidget->setObjectName(QStringLiteral("bottomwidget"));
        bottomwidget->setGeometry(QRect(10, 480, 474, 75));
        horizontalLayout_2 = new QHBoxLayout(bottomwidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        premusicButton = new QToolButton(bottomwidget);
        premusicButton->setObjectName(QStringLiteral("premusicButton"));

        horizontalLayout_2->addWidget(premusicButton);

        playmusicButton = new QToolButton(bottomwidget);
        playmusicButton->setObjectName(QStringLiteral("playmusicButton"));

        horizontalLayout_2->addWidget(playmusicButton);

        nextmusicButton = new QToolButton(bottomwidget);
        nextmusicButton->setObjectName(QStringLiteral("nextmusicButton"));

        horizontalLayout_2->addWidget(nextmusicButton);

        palytimelabel_3 = new QLabel(bottomwidget);
        palytimelabel_3->setObjectName(QStringLiteral("palytimelabel_3"));

        horizontalLayout_2->addWidget(palytimelabel_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        palytimelabel_2 = new QLabel(bottomwidget);
        palytimelabel_2->setObjectName(QStringLiteral("palytimelabel_2"));

        verticalLayout_3->addWidget(palytimelabel_2);

        palytimelabel = new QLabel(bottomwidget);
        palytimelabel->setObjectName(QStringLiteral("palytimelabel"));

        verticalLayout_3->addWidget(palytimelabel);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lyriclabel = new QLabel(bottomwidget);
        lyriclabel->setObjectName(QStringLiteral("lyriclabel"));
        lyriclabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lyriclabel);

        playtimeSlider = new QSlider(bottomwidget);
        playtimeSlider->setObjectName(QStringLiteral("playtimeSlider"));
        playtimeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(playtimeSlider);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        palytimetotallabel_2 = new QLabel(bottomwidget);
        palytimetotallabel_2->setObjectName(QStringLiteral("palytimetotallabel_2"));

        verticalLayout_4->addWidget(palytimetotallabel_2);

        palytimetotallabel = new QLabel(bottomwidget);
        palytimetotallabel->setObjectName(QStringLiteral("palytimetotallabel"));

        verticalLayout_4->addWidget(palytimetotallabel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        blanklabel3 = new QLabel(bottomwidget);
        blanklabel3->setObjectName(QStringLiteral("blanklabel3"));

        verticalLayout_5->addWidget(blanklabel3);

        volumeButton = new QToolButton(bottomwidget);
        volumeButton->setObjectName(QStringLiteral("volumeButton"));

        verticalLayout_5->addWidget(volumeButton);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        blanklabel4 = new QLabel(bottomwidget);
        blanklabel4->setObjectName(QStringLiteral("blanklabel4"));

        verticalLayout_6->addWidget(blanklabel4);

        volumeSlider = new QSlider(bottomwidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(80, 29));
        volumeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(volumeSlider);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        blanklabel3_2 = new QLabel(bottomwidget);
        blanklabel3_2->setObjectName(QStringLiteral("blanklabel3_2"));

        verticalLayout_7->addWidget(blanklabel3_2);

        playmodeButton = new QToolButton(bottomwidget);
        playmodeButton->setObjectName(QStringLiteral("playmodeButton"));

        verticalLayout_7->addWidget(playmodeButton);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        blanklabel3_3 = new QLabel(bottomwidget);
        blanklabel3_3->setObjectName(QStringLiteral("blanklabel3_3"));

        verticalLayout_8->addWidget(blanklabel3_3);

        winlrcButton = new QToolButton(bottomwidget);
        winlrcButton->setObjectName(QStringLiteral("winlrcButton"));

        verticalLayout_8->addWidget(winlrcButton);

        verticalLayout_8->setStretch(0, 3);
        verticalLayout_8->setStretch(1, 7);

        horizontalLayout_2->addLayout(verticalLayout_8);

        midwidget = new QWidget(centralWidget);
        midwidget->setObjectName(QStringLiteral("midwidget"));
        midwidget->setGeometry(QRect(10, 80, 631, 379));
        listwidget = new QWidget(midwidget);
        listwidget->setObjectName(QStringLiteral("listwidget"));
        listwidget->setGeometry(QRect(0, 0, 137, 361));
        horizontalLayout_3 = new QHBoxLayout(listwidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(8, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        recommendlabel = new QLabel(listwidget);
        recommendlabel->setObjectName(QStringLiteral("recommendlabel"));

        verticalLayout->addWidget(recommendlabel);

        foundmusicButton = new QPushButton(listwidget);
        foundmusicButton->setObjectName(QStringLiteral("foundmusicButton"));

        verticalLayout->addWidget(foundmusicButton);

        privateFMButton = new QPushButton(listwidget);
        privateFMButton->setObjectName(QStringLiteral("privateFMButton"));

        verticalLayout->addWidget(privateFMButton);

        videoButton = new QPushButton(listwidget);
        videoButton->setObjectName(QStringLiteral("videoButton"));

        verticalLayout->addWidget(videoButton);

        friendButton = new QPushButton(listwidget);
        friendButton->setObjectName(QStringLiteral("friendButton"));

        verticalLayout->addWidget(friendButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        mymusiclabel = new QLabel(listwidget);
        mymusiclabel->setObjectName(QStringLiteral("mymusiclabel"));

        verticalLayout->addWidget(mymusiclabel);

        locmusicButton = new QPushButton(listwidget);
        locmusicButton->setObjectName(QStringLiteral("locmusicButton"));

        verticalLayout->addWidget(locmusicButton);

        downloadButton = new QPushButton(listwidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));

        verticalLayout->addWidget(downloadButton);

        mymusicButton = new QPushButton(listwidget);
        mymusicButton->setObjectName(QStringLiteral("mymusicButton"));

        verticalLayout->addWidget(mymusicButton);

        myradioButton = new QPushButton(listwidget);
        myradioButton->setObjectName(QStringLiteral("myradioButton"));

        verticalLayout->addWidget(myradioButton);

        myenshrineButton = new QPushButton(listwidget);
        myenshrineButton->setObjectName(QStringLiteral("myenshrineButton"));

        verticalLayout->addWidget(myenshrineButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        listScrollBar = new QScrollBar(listwidget);
        listScrollBar->setObjectName(QStringLiteral("listScrollBar"));
        listScrollBar->setEnabled(true);
        listScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(listScrollBar);

        listScrollBar->raise();
        contentwidget = new QWidget(midwidget);
        contentwidget->setObjectName(QStringLiteral("contentwidget"));
        contentwidget->setGeometry(QRect(150, 0, 441, 361));
        titlewidget = new QWidget(centralWidget);
        titlewidget->setObjectName(QStringLiteral("titlewidget"));
        titlewidget->setGeometry(QRect(-3, 1, 594, 62));
        titlewidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(titlewidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 0, 8, 2);
        logoButton = new QPushButton(titlewidget);
        logoButton->setObjectName(QStringLiteral("logoButton"));

        horizontalLayout->addWidget(logoButton);

        TitleButton = new QPushButton(titlewidget);
        TitleButton->setObjectName(QStringLiteral("TitleButton"));
        QFont font1;
        font1.setPointSize(22);
        TitleButton->setFont(font1);
        TitleButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(TitleButton);

        horizontalSpacer = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leftButton = new QPushButton(titlewidget);
        leftButton->setObjectName(QStringLiteral("leftButton"));

        horizontalLayout->addWidget(leftButton);

        rightButton = new QPushButton(titlewidget);
        rightButton->setObjectName(QStringLiteral("rightButton"));

        horizontalLayout->addWidget(rightButton);

        searchEdit = new QLineEdit(titlewidget);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        horizontalLayout->addWidget(searchEdit);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(51, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        minButton = new QToolButton(titlewidget);
        minButton->setObjectName(QStringLiteral("minButton"));

        horizontalLayout->addWidget(minButton);

        maxButton = new QToolButton(titlewidget);
        maxButton->setObjectName(QStringLiteral("maxButton"));

        horizontalLayout->addWidget(maxButton);

        closeButton = new QToolButton(titlewidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);

        logoButton->raise();
        TitleButton->raise();
        leftButton->raise();
        rightButton->raise();
        searchEdit->raise();
        minButton->raise();
        maxButton->raise();
        closeButton->raise();
        MusicWindow->setCentralWidget(centralWidget);
        midwidget->raise();
        bottomwidget->raise();
        titlewidget->raise();
        QWidget::setTabOrder(nextmusicButton, minButton);
        QWidget::setTabOrder(minButton, locmusicButton);
        QWidget::setTabOrder(locmusicButton, downloadButton);
        QWidget::setTabOrder(downloadButton, mymusicButton);
        QWidget::setTabOrder(mymusicButton, myradioButton);
        QWidget::setTabOrder(myradioButton, myenshrineButton);
        QWidget::setTabOrder(myenshrineButton, playtimeSlider);
        QWidget::setTabOrder(playtimeSlider, volumeButton);
        QWidget::setTabOrder(volumeButton, volumeSlider);
        QWidget::setTabOrder(volumeSlider, playmodeButton);
        QWidget::setTabOrder(playmodeButton, winlrcButton);
        QWidget::setTabOrder(winlrcButton, logoButton);
        QWidget::setTabOrder(logoButton, TitleButton);
        QWidget::setTabOrder(TitleButton, leftButton);
        QWidget::setTabOrder(leftButton, rightButton);
        QWidget::setTabOrder(rightButton, foundmusicButton);
        QWidget::setTabOrder(foundmusicButton, closeButton);
        QWidget::setTabOrder(closeButton, maxButton);
        QWidget::setTabOrder(maxButton, searchEdit);
        QWidget::setTabOrder(searchEdit, privateFMButton);
        QWidget::setTabOrder(privateFMButton, premusicButton);
        QWidget::setTabOrder(premusicButton, friendButton);
        QWidget::setTabOrder(friendButton, videoButton);
        QWidget::setTabOrder(videoButton, playmusicButton);

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        premusicButton->setText(QString());
        playmusicButton->setText(QString());
        nextmusicButton->setText(QString());
        palytimelabel_3->setText(QString());
        palytimelabel_2->setText(QString());
        palytimelabel->setText(QApplication::translate("MusicWindow", "00:00", 0));
        lyriclabel->setText(QString());
        palytimetotallabel_2->setText(QString());
        palytimetotallabel->setText(QApplication::translate("MusicWindow", "00:00", 0));
        blanklabel3->setText(QString());
        volumeButton->setText(QString());
        blanklabel4->setText(QString());
        blanklabel3_2->setText(QString());
        playmodeButton->setText(QString());
        blanklabel3_3->setText(QString());
        winlrcButton->setText(QString());
        recommendlabel->setText(QApplication::translate("MusicWindow", "\346\216\250\350\215\220", 0));
        foundmusicButton->setText(QApplication::translate("MusicWindow", "\345\217\221\347\216\260\351\237\263\344\271\220", 0));
        privateFMButton->setText(QApplication::translate("MusicWindow", "\351\237\263\344\271\220\344\270\226\347\225\214", 0));
        videoButton->setText(QApplication::translate("MusicWindow", "\346\210\221\347\232\204\346\224\266\350\227\217", 0));
        friendButton->setText(QApplication::translate("MusicWindow", "\346\233\264\346\226\260\346\255\214\350\257\215", 0));
        mymusiclabel->setText(QApplication::translate("MusicWindow", "\346\210\221\347\232\204\351\237\263\344\271\220", 0));
        locmusicButton->setText(QApplication::translate("MusicWindow", "\346\267\273\345\212\240\346\234\254\345\234\260\351\237\263\344\271\220", 0));
        downloadButton->setText(QApplication::translate("MusicWindow", "\345\210\207\346\215\242\351\241\265\351\235\242", 0));
        mymusicButton->setText(QApplication::translate("MusicWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", 0));
        myradioButton->setText(QApplication::translate("MusicWindow", "\346\222\255\346\224\276\347\225\214\351\235\242", 0));
        myenshrineButton->setText(QApplication::translate("MusicWindow", "\346\220\234\347\264\242\345\210\227\350\241\250", 0));
        logoButton->setText(QString());
        TitleButton->setText(QApplication::translate("MusicWindow", "\344\272\221\351\237\263\344\271\220", 0));
        leftButton->setText(QApplication::translate("MusicWindow", "<", 0));
        rightButton->setText(QApplication::translate("MusicWindow", ">", 0));
        minButton->setText(QApplication::translate("MusicWindow", "...", 0));
        maxButton->setText(QApplication::translate("MusicWindow", "...", 0));
        closeButton->setText(QApplication::translate("MusicWindow", "...", 0));
        Q_UNUSED(MusicWindow);
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
