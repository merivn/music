#include "baseWidget.h"
#include<QStyleOption>
#include<QPainter>


#include "MusicWindow.h"

baseWidget::baseWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}
void baseWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void baseWidget::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);
}

void baseWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(MusicWindow::GetInstance())
       MusicWindow::GetInstance()->mouseMoveEvent(e);
    QWidget::mouseMoveEvent(e);
}

void baseWidget::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);
}
