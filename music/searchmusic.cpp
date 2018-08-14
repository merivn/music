#include "searchmusic.h"
#include "ui_searchmusic.h"
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QEventLoop>
#include<QDebug>


searchmusic::searchmusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchmusic)
{
    ui->setupUi(this);
    m_contextMenu = new QMenu;
    m_addAction = new QAction("add Item",this);
    m_delAction = new QAction("del Item",this);
    m_contextMenu->addAction(m_addAction);
    m_contextMenu->addAction(m_delAction);
}

searchmusic::~searchmusic()
{
    delete ui;
}

void searchmusic::mousePressEvent(QMouseEvent *event)
{
    //确保右键点击，然后跳出菜单.
    if (event->button() == Qt::RightButton)
    {
        m_contextMenu->exec(event->globalPos());
    }
    //要继续保留QListWidget原有的点击事件.
    QWidget::mousePressEvent(event);
}
