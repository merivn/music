#include "mylrc.h"
#include "ui_mylrc.h"

mylrc::mylrc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mylrc)
{
    ui->setupUi(this);
}

mylrc::~mylrc()
{
    delete ui;
}
