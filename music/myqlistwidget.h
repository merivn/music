#ifndef MYQLISTWIDGET_H
#define MYQLISTWIDGET_H
#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMouseEvent>
#include <QDebug>

class myQlistWidget : public QListWidget
{
    Q_OBJECT
public:
    myQlistWidget(QWidget *parent);
    ~myQlistWidget();
protected:
    void mousePressEvent(QMouseEvent *event);
public slots:
    void trigerMenu(QAction* act);
signals:
    void sig_collection();

private:
    QMenu *m_contextMenu;
    QAction *m_addAction;
    QAction *m_delAction;
};

#endif // MYQLISTWIDGET_H
