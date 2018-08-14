#ifndef LYRICWIDGET_H
#define LYRICWIDGET_H

//歌词页面

#include <QWidget>
#include <QMap>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QFile>
#include <QOpenGLWidget>
#include "baseWidget.h"
#include "LyricWidget.h"

typedef int  CONVERT_CODE;

#define   CONVERT_SUCCESS       0x00
#define   CONVERT_FILE_EMPTY    0x01
#define   CONVERT_PARA_ERR      0x02
#define   CONVERT_FORMAT_ERR    0x03
#define   CONVERT_UNKNOWN       0x04

struct ItemInfo{
    int index;
    int alpha;
    int Y;
    bool hightLight;
    QString strText;
};

class LyricWidget : public baseWidget
{
    Q_OBJECT

public:
    LyricWidget(QWidget *parent = 0);
    ~LyricWidget();

//get current Row lrc by index

    QString GetLrcByIndex(int index);

//get start pos by index
    qint64 GetPosByindex(int index);

//get the lrc by time
    QString GetLrcByTime(qint64 time);

//get index by time
    int GetIndexByTime(qint64 time);

//get mask length
    void GetMaskLen(int nFontSize);


    void analyzeLrcContent(QByteArray&,const QString &filePath);

    void clearLrc();

    void getPosInfo(int &keyTime,int &interval, float &precent, QString &str);

    void setOriginalStatus();
    CONVERT_CODE  KrcDecode2(QFile  &KrcFile, QFile  &LrcFile);
protected:
    virtual void paintEvent(QPaintEvent*event);

public slots:
    void slot_timer();
public slots:
    void positionChanged1(qint64 length);
private:
//Draw single row text
    void DrawItem(QPainter&Painter,ItemInfo &index);

//
    QMap<qint64,QString> m_lineMap;
    QList<QMap<int,QString> > m_word_list;
    QList<QMap<int ,int> > m_interval_list; //interval,间隔时间
//

    QString m_strCurLrc;
    QTimer m_timer;
    QFont m_normalFont;
    qint64 m_nCurPos;
    qint64 m_nCurStartPos;
    float m_nMaskLen;
    int m_nCurIndex;
    int m_nSroIndex;
    int m_nOffset;
    int m_nFontPixSize;
    QColor m_HLColor;   //hightlight
    QColor m_NlColor;   //normal
};

#endif // LYRICWIDGET_H
