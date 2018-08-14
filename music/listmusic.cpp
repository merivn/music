#include "listmusic.h"
#include "ui_listmusic.h"

listmusic::listmusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listmusic)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,\
                     QBrush(QPixmap(":/background/1.jpg").scaled(/*缩放背景图.*/this->size(),\
                     Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);
}
void listmusic::listshow(void){

    qDebug()<<" test";

}
listmusic::~listmusic()
{
    delete ui;
}

void listmusic::on_pushButton_clicked()
{
//    parent->show();

    parentWidget()->show();
}
