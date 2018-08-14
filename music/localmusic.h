#ifndef LOCALMUSIC_H
#define LOCALMUSIC_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPalette>
#include <QFile>
namespace Ui {
class localmusic;
}

class localmusic : public QWidget
{
    Q_OBJECT

public:
    void setStyle(const QString &style);
    explicit localmusic(QWidget *parent = 0);
    ~localmusic();

private:
    Ui::localmusic *ui;
};

#endif // LOCALMUSIC_H
