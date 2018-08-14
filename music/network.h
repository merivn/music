#ifndef NETWORK_H
#define NETWORK_H

//酷狗API相关
#include <QObject>
#include<QObject>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QImage>
#include<QPixmap>
#include<QFile>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QEventLoop>
#include<QDebug>
#include <QDir>
#include <QApplication>

//play method
//http://m.kugou.com/app/i/getSongInfo.php?cmd=playInfo&hash=
//http://www.kugou.com/yy/index.php?r=play/getdata&hash
//4C285C68EBEFAD7D8602D2D14D48F725
//AFF3B6219C15D030F957B82FF50AA91E
//http://m.kugou.com/app/i/getSongInfo.php?cmd=playInfo&hash=4B25BAE1921E9F706D33FAB2E846B10E
#define USE_NETCLOUD 1

#define BG_URL "http://artistpicserver.kuwo.cn/pic.web?type=big_artist_pic&pictype=url&content=list&id=0&name=%1&from=pc&json=1&version=1&width=1920&height=1080"
#define SONG_URL "http://itwusun.com/search/wy/%1?&f=json&size=50&p=%2&sign=itwusun"

#define URL_KGPLAY "http://m.kugou.com/app/i/getSongInfo.php?cmd=playInfo&hash=%1"
#define KGLrcPart0 "http://songsearch.kugou.com/song_search_v2?keyword=%1&page=1&pagesize=40&filter=0&bitrate=0&isfuzzy=0&inputtype=2&platform=PcFilter&userid=312986171&clientver=8100&iscorrection=3"
#define KGLrcPart1 "http://lyrics.kugou.com/search?ver=1&man=no&client=pc&keyword=%1&duration=%2&hash=%3"//&hash=9c6fd9b90800f7a37f6821c07bc0f906 9C6FD9B90800F7A37F6821C07BC0F906 b3c9045aa086236dc78a59357bdf73ac
#define KGLrcPart2 "http://lyrics.kugou.com/download?ver=1&client=pc&id=%1&accesskey=%2&fmt=krc"

#define ITWUSUN "http://api.itwusun.com/music/search/wy/%1?format=json&keyword=%2&sign=a5cc0a8797539d3a1a4f7aeca5b695b9"

struct ItemResult
{
   QString strFullName;
   QString strAlbum;

   QString strUrl;
   QString strMusicName;
   QString strSinger;
   QString strHash;
   QString strDur;
};
enum SearchStatus{Started=0x00,Searching,Finished};

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = 0);
    ~network();
    void requestSong(const QString&);
    void requestSonglist(const QString&);
    void requestSongurl(const QString &);
     void requestSong2(const QString&,int);
    void requestBgPic(const QString &author);
    void requestlrc(const QString &name,qint64 totaltime,const QString &saveloaction,const QString &strHash="");
    const QImage &BgWhiteChange(QImage& image , int brightness);
signals:
   void sig_reqSongStatus(const ItemResult&,SearchStatus);
   void sig_reqSongStatus2(const ItemResult&,SearchStatus);
   void sig_setBgpix(const QStringList&,const QString& author);
   void sig_seturl(const QString&);
   void dolrcworkfinished(const QByteArray&,const QString&);
   void striderror();
public slots:

};

#endif // NETWORK_H
