#ifndef MYCOLLECTWIDGET_H
#define MYCOLLECTWIDGET_H
#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMouseEvent>
#include <QDebug>


class mycollectwidget : public QListWidget
{
        Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event);
public slots:
    void trigerMenu(QAction* act);
signals:
    void sig_delete_collect();
public:
    mycollectwidget(QWidget *parent);
    ~mycollectwidget();
private:
    QMenu *m_contextMenu;
    QAction *m_addAction;
    QAction *m_delAction;
};

#endif // MYCOLLECTWIDGET_H
