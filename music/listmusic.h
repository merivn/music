#ifndef LISTMUSIC_H
#define LISTMUSIC_H

#include <QWidget>
#include <QDebug>
#include "ui_listmusic.h"

namespace Ui {
class listmusic;
}

class listmusic : public QWidget
{
    Q_OBJECT

public:
    void listshow(void);
    explicit listmusic(QWidget *parent = 0);
    ~listmusic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listmusic *ui;
};

#endif // LISTMUSIC_H
