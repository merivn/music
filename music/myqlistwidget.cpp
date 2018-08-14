#include "myqlistwidget.h"

myQlistWidget::myQlistWidget(QWidget *parent)
    : QListWidget(parent)
{
    m_contextMenu = new QMenu;
      m_addAction = new QAction("添加到我的收藏",this);
    //  m_delAction = new QAction("del Item",this);
      m_contextMenu->addAction(m_addAction);
   //   m_contextMenu->addAction(m_delAction);
       connect(m_contextMenu,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));
}

myQlistWidget::~myQlistWidget()
{

}

void myQlistWidget::mousePressEvent(QMouseEvent *event)
{
    QListWidgetItem * durItem;
    int curIndex;
    //确保右键点击，然后跳出菜单.
    if (event->button() == Qt::RightButton)
    {
        durItem = this->itemAt(event->pos());
        curIndex = this->row(durItem);
//         qDebug()<< curIndex ;
       // this->setCurrentItem(curIndex);
        this->setCurrentRow(curIndex);
        m_contextMenu->exec(event->globalPos());
    }
    //要继续保留QListWidget原有的点击事件.
    QListWidget::mousePressEvent(event);
}
void myQlistWidget::trigerMenu(QAction* act)
{
    if(act->text() == "添加到我的收藏")
    {
//        qDebug()<<"新建菜单被按下";
         emit sig_collection();
    }
}
