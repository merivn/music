#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include "allhead.h"
#define PAGE_LRC 2
//#define DEbug "debug/"
//#define DEbug ""
//#define DEbug "release/"
namespace Ui {
class MusicWindow;
}

class MusicWindow : public QMainWindow
{
    Q_OBJECT
public:
    static void setStyle(const QString &style);
    QString Time(qint64 time);
public:
    explicit MusicWindow(QWidget *parent = 0);
    ~MusicWindow();

    static MusicWindow *GetInstance(){return s_pMainWnd;}

 //initialize Instance
    static MusicWindow * InitInstance();
protected:
     static MusicWindow *s_pMainWnd;
    //去掉标题栏后用鼠标事件移动程序主窗口
    void setBackgroundPicture(void);

    void musicplay(void);
    void musicpause(bool musicplay);

    void init_musicname(void);
    int traverse(const QString& path);
    void init_windowui(void);
    void init_musicplay(void);
    void init_var(void);
    void init_database(void);
    void set_connetfunc(void);

    void initNetwork();
    void keyPressEvent(QKeyEvent * event);
    void to_play();
    void to_play2();

public:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
private slots:
    void on_minButton_clicked();

    void on_maxButton_clicked();


    void on_closeButton_clicked();

    void on_playmusicButton_clicked();

    void on_premusicButton_clicked();

    void on_nextmusicButton_clicked();
//    void gettime(void);
    //添加本地音乐
    void on_locmusicButton_clicked();
    void updatePosition(qint64 position);

    void on_volumeButton_clicked();

    void on_playmodeButton_clicked();

    void updateDuration(qint64 duration);
    void  updateText();

    void listDoubleClicked();


    void listDoubleClicked2();

    void collectDoubleClicked();

    void listclicked2(QListWidgetItem*);

//    void lyrictDoubleClicked();

    void on_downloadButton_clicked();

    void on_TitleButton_clicked();

    void on_mymusicButton_clicked();

    void on_myradioButton_clicked();

    void on_foundmusicButton_clicked();

    void onSearch(bool);
 //   void slot_requestSong(bool);
//    void test();
     void slot_timelineAnimation(int index);

     void slot_requestSong(const ItemResult&,SearchStatus);
     void slot_requestSong2(const ItemResult&,SearchStatus);
     void slot_setBgPix(const QStringList&,const QString &);



//     void slot_replyLrc(int x);
     void on_myenshrineButton_clicked();
     void  slot_pagechange(int index);

     void on_videoButton_clicked();

     void on_friendButton_clicked();
     void on_privateFMButton_clicked();

     void on_winlrcButton_clicked();

public slots:
    void slot_lrc(QByteArray,QString);
    void slot_seturl(const QString &);
    void slot_collection();
    void slot_delete_collect();
signals:
//    void sig_search();

public:
    void switchPage();
    void showlrc();
private:
    Ui::MusicWindow *ui;
    QPoint last; //鼠标事件
    QIcon icon;
    /*窗口正常、最大*/
    bool m_maxnor;
    /*音乐播放停止*/
    bool m_musicplay;
    //音量、静音
    bool volume_silence;
    //播放模式
    QMediaPlaylist::PlaybackMode m_playmode;
    //    bool b_music_play;
    //播放列表
    QMediaPlaylist *playlist;
    QMediaPlaylist *searchlist;
    QMediaPlaylist *collectlist;
    QMediaPlaylist *q_MediaPlaylist;

    QMediaPlayer *musicPlayer;
    QVector<QString> stringVector;
    int m_index;
    qint64 totaltime;

    QListWidget *listWidget;
//    QListWidget *searchWidget;
    myQlistWidget *searchWidget;
    mycollectwidget *collect_widget;
    QListWidget *q_ListWidget;

    QStackedWidget *pages;
    listmusic *listt;
    localmusic *localt;
    collectwidget *collectt;
    mylrc *mylrct;
    searchmusic *searcht;
    QAction *pTrailingAction;
    network search;
    LyricWidget *lyrict;
    QTimeLine m_timeline;
    QStringList m_picList;
    QString m_duration;
    int test;
    bool music_change;

    QString s_musicname;
    QString s_dur;
    int l_dur;
    int cur_music_volume;
    QString s_templocal;
    QString s_strHash;
    int s_n;
    bool music_end;
    bool list_hide;
    QRect lyrict_rect;
   // int lrc_list_num;
    QStringList lrc_Hash;
    QStringList music_search_list;
    QStringList music_Url;
    QStringList music_dur;

    QStringList col_name;
    QStringList col_hash;
    QStringList col_dur;
    database d;
    bool iscollect;
};

#endif // MUSICWINDOW_H

