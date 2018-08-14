#ifndef SEARCHMUSIC_H
#define SEARCHMUSIC_H

#include <QWidget>
#include<QObject>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QImage>
#include<QPixmap>

#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMouseEvent>

namespace Ui {
class searchmusic;
}

class searchmusic : public QWidget
{
    Q_OBJECT

public:
    explicit searchmusic(QWidget *parent = 0);
    ~searchmusic();
     void mousePressEvent(QMouseEvent *event);
private:
     QMenu *m_contextMenu;
     QAction *m_addAction;
     QAction *m_delAction;
    Ui::searchmusic *ui;
};

#endif // SEARCHMUSIC_H
