#include "localmusic.h"
#include "ui_localmusic.h"

localmusic::localmusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::localmusic)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(ui->mainwidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    ui->mainwidget->setAttribute(Qt::WA_StyledBackground,true);

}

void localmusic::setStyle(const QString &style) {
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}
localmusic::~localmusic()
{
    delete ui;
}
