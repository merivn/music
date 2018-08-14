#include "mycollectwidget.h"

mycollectwidget::mycollectwidget(QWidget *parent)
    :QListWidget(parent)
{
    m_contextMenu = new QMenu;
      m_addAction = new QAction("删除",this);
    //  m_delAction = new QAction("del Item",this);
      m_contextMenu->addAction(m_addAction);
   //   m_contextMenu->addAction(m_delAction);
       connect(m_contextMenu,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));
}

mycollectwidget::~mycollectwidget()
{

}

void mycollectwidget::mousePressEvent(QMouseEvent *event)
{

    QListWidgetItem * durItem;
    int curIndex;
    //确保右键点击，然后跳出菜单.
    if (event->button() == Qt::RightButton)
    {
        durItem = this->itemAt(event->pos());
        curIndex = this->row(durItem);
        this->setCurrentRow(curIndex);
        m_contextMenu->exec(event->globalPos());
    }
    //要继续保留QListWidget原有的点击事件.
    QListWidget::mousePressEvent(event);
}
void mycollectwidget::trigerMenu(QAction* act)
{
    if(act->text() == "删除")
    {
//        qDebug()<<"新建菜单被按下";
         emit sig_delete_collect();
    }
}
