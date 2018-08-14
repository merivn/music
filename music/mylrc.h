#ifndef MYLRC_H
#define MYLRC_H

#include <QWidget>

#include <QVBoxLayout>
#include <QPalette>
#include <QFile>
namespace Ui {
class mylrc;
}

class mylrc : public QWidget
{
    Q_OBJECT

public:
    explicit mylrc(QWidget *parent = 0);
    ~mylrc();

private:
    Ui::mylrc *ui;
};

#endif // MYLRC_H
