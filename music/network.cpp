#include "network.h"

network::network(QObject *parent) : QObject(parent)
{

}

network::~network()
{

}

void network::requestSong(const QString &strReq)//请求歌曲
{

    ItemResult Item={0};
    emit sig_reqSongStatus(Item,SearchStatus::Started);

    QString strTemp(KGLrcPart0);
    strTemp=strTemp.arg(strReq);

    QNetworkRequest request;
    QNetworkAccessManager manger;
    request.setUrl(strTemp);
    QNetworkReply *reply=manger.get(request);

    QEventLoop loop;
    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    loop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytTemp= reply->readAll();
        reply->deleteLater();
        QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
        QJsonObject objTemp=doc0.object();
        objTemp= objTemp.value("data").toObject();
        QJsonArray array0= objTemp.value("lists").toArray();
        for(int i=0;i<array0.size();++i)
        {
            objTemp= array0.at(i).toObject();

            Item.strFullName=objTemp.value("FileName").toString();
            Item.strHash= objTemp.value("FileHash").toString();
            Item.strMusicName= objTemp.value("SongName").toString();
            Item.strSinger=objTemp.value("SingerName").toString();
            Item.strAlbum=objTemp.value("AlbumName").toString();
            int ndur=objTemp.value("Duration").toInt();
            QTime time(0, ndur/60, ndur%60);
            Item.strDur= time.toString("mm:ss");
        //    qDebug()<<Item.strSinger<< Item.strMusicName << Item.strDur;
            strTemp=URL_KGPLAY;
            strTemp=strTemp.arg(Item.strHash);
            request.setUrl(strTemp);

            QNetworkReply *reply=manger.get(request);
            loop.exec();
            if(reply->error()==QNetworkReply::NoError)
            {
                 bytTemp= reply->readAll();
                 QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
                 objTemp=doc0.object();
                 Item.strUrl="";
                 Item.strUrl= objTemp.value("url").toString();

       //          qDebug()<<Item.strUrl;
                emit sig_reqSongStatus(Item,SearchStatus::Searching);
            }
            reply->deleteLater();
        }
    }
    emit sig_reqSongStatus(Item,SearchStatus::Finished);
    reply->deleteLater();
}
void network::requestSonglist(const QString &strReq)//请求歌曲列表
{

    ItemResult Item={0};
    emit sig_reqSongStatus(Item,SearchStatus::Started);

    QString strTemp(KGLrcPart0);
    strTemp=strTemp.arg(strReq);

    QNetworkRequest request;
    QNetworkAccessManager manger;
    request.setUrl(strTemp);
    QNetworkReply *reply=manger.get(request);

    QEventLoop loop;
    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    loop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytTemp= reply->readAll();
        reply->deleteLater();
        QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
        QJsonObject objTemp=doc0.object();
        objTemp= objTemp.value("data").toObject();
        QJsonArray array0= objTemp.value("lists").toArray();
        for(int i=0;i<array0.size();++i)
        {
            objTemp= array0.at(i).toObject();

            Item.strFullName=objTemp.value("FileName").toString();
            Item.strHash= objTemp.value("FileHash").toString();
            Item.strMusicName= objTemp.value("SongName").toString();
            Item.strSinger=objTemp.value("SingerName").toString();
            Item.strAlbum=objTemp.value("AlbumName").toString();
            int ndur=objTemp.value("Duration").toInt();
            QTime time(0, ndur/60, ndur%60);
            Item.strDur= time.toString("mm:ss");
            emit sig_reqSongStatus(Item,SearchStatus::Searching);
        }
    }
    emit sig_reqSongStatus(Item,SearchStatus::Finished);
    reply->deleteLater();
}

void network::requestSongurl(const QString &strReq)//请求歌曲网址
{



//    QNetworkAccessManager manger;
//    QNetworkReply *reply;
//    reply=manger.get(QNetworkRequest(strTemp));

//    QEventLoop loop;
//    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
//    loop.exec();
//    QByteArray bytTemp=reply->readAll();
//    reply->deleteLater();

//    QJsonDocument doc=QJsonDocument::fromJson(bytTemp);
//    QJsonObject obj=doc.object();
//    QJsonArray array=obj.value("array").toArray();

//    QStringList picList;



    QString strUrl;
    QString strTemp=URL_KGPLAY;
    strTemp=strTemp.arg(strReq);

    QNetworkAccessManager manger;
    QNetworkRequest request;
    request.setUrl(strTemp);
    QNetworkReply *reply=manger.get(request);
    QEventLoop loop;
    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    loop.exec();
    if(reply->error()==QNetworkReply::NoError)
    {

        QByteArray bytTemp= reply->readAll();
        reply->deleteLater();
        QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
        QJsonObject objTemp=doc0.object();
        strUrl="";
        strUrl= objTemp.value("url").toString();
                //  qDebug()<<strUrl;
    }
    emit sig_seturl(strUrl);
   // emit sig_reqSongStatus(Item,SearchStatus::Finished);
}
void network::requestSong2(const QString &strReq,int musicid)//请求歌曲 ，测试用
{



    ItemResult Item={0};
    emit sig_reqSongStatus2(Item,SearchStatus::Started);

    QString strTemp(KGLrcPart0);
    strTemp=strTemp.arg(strReq);

    QNetworkRequest request;
    QNetworkAccessManager manger;
    request.setUrl(strTemp);
    QNetworkReply *reply=manger.get(request);
    QEventLoop loop;
//             qDebug()<< "test1";
//           qDebug()<<  strTemp;
   // disconnect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));

    loop.exec();

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytTemp= reply->readAll();
        reply->deleteLater();
        QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
        QJsonObject objTemp=doc0.object();
        objTemp= objTemp.value("data").toObject();
        QJsonArray array0= objTemp.value("lists").toArray();
//        for(int i=0;i<array0.size();++i)
//        {

            objTemp= array0.at(musicid).toObject();

            Item.strFullName=objTemp.value("FileName").toString();
            Item.strHash= objTemp.value("FileHash").toString();
            Item.strMusicName= objTemp.value("SongName").toString();
            Item.strSinger=objTemp.value("SingerName").toString();
            Item.strAlbum=objTemp.value("AlbumName").toString();
            int ndur=objTemp.value("Duration").toInt();
            QTime time(0, ndur/60, ndur%60);
            Item.strDur= time.toString("mm:ss");
        //    qDebug()<<Item.strSinger<< Item.strMusicName << Item.strDur;
            strTemp=URL_KGPLAY;
            strTemp=strTemp.arg(Item.strHash);
            request.setUrl(strTemp);

            QNetworkReply *reply=manger.get(request);
            loop.exec();
            if(reply->error()==QNetworkReply::NoError)
            {
                 bytTemp= reply->readAll();
                 QJsonDocument doc0=QJsonDocument::fromJson(bytTemp);
                 objTemp=doc0.object();
                 Item.strUrl="";
                 Item.strUrl= objTemp.value("url").toString();

       //          qDebug()<<Item.strUrl;
                emit sig_reqSongStatus2(Item,SearchStatus::Searching);
            }
            reply->deleteLater();

    }
    emit sig_reqSongStatus2(Item,SearchStatus::Finished);
    reply->deleteLater();



}

const QImage &network::BgWhiteChange(QImage &image , int brightness)
    {
        uchar *line =image.scanLine(0);
            uchar *pixel = line;
            for (int y = 0; y < image.height(); ++y)
            {
                pixel = line;
                for (int x = 0; x < image.width(); ++x)
                {
                    *pixel = qBound(0, *pixel + brightness, 255);
                    *(pixel + 1) = qBound(0, *(pixel + 1) + brightness, 255);
                    *(pixel + 2) = qBound(0, *(pixel + 2) + brightness, 255);
                    pixel += 4;
                }
                line += image.bytesPerLine();
            }
            return image;
}
void network::requestBgPic(const QString &author)  //请求歌手图片
{

    QString dir_str = "au_bg_pic/%1";
    dir_str=dir_str.arg(author);
    QDir dir;
    if (!dir.exists(dir_str))
    {
        dir.mkpath(dir_str);
    }
        QString strTemp(BG_URL);
        strTemp=strTemp.arg(author);

        QNetworkAccessManager manger;
        QNetworkReply *reply;
        reply=manger.get(QNetworkRequest(strTemp));

        QEventLoop loop;
        connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
        loop.exec();
        QByteArray bytTemp=reply->readAll();
        reply->deleteLater();

        QJsonDocument doc=QJsonDocument::fromJson(bytTemp);
        QJsonObject obj=doc.object();
        QJsonArray array=obj.value("array").toArray();

        QStringList picList;

        for(int i=0;i<array.count();i++)
        {
           obj= array.at(i).toObject();
           strTemp=obj.value("bkurl").toString();
           if(!strTemp.isEmpty())//如果不为空
           {
              //   qDebug()<<strTemp;

                   reply=manger.get(QNetworkRequest(strTemp));
                   connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
                   loop.exec();

                   bytTemp=reply->readAll();

                   QImage image;
                   image.loadFromData(bytTemp);


                   image=BgWhiteChange(image,-50);

                   strTemp=QString("au_bg_pic/%1/%2.jpg").arg(author).arg(i);
              //      qDebug() <<strTemp;
                   image.save(strTemp);
                   picList<<strTemp;
                   reply->deleteLater();
               }
           }
            if(!picList.isEmpty())
                emit sig_setBgpix(picList,author);


  }

void network::requestlrc(const QString &lrcname,qint64 nTotalTime,const QString &lrcloaction,const QString &strHash)//请求歌词
{
    QByteArray arrayTemp;
    QString accesskey;
    QString strID;
    QString strHash2=strHash;
    QString strTemp(KGLrcPart0);
    QString songname=lrcname;
    songname.replace("&"," ");
    QNetworkRequest request;
    QNetworkAccessManager manger;
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    QJsonArray jsonArray;
    QEventLoop loop;
    QNetworkReply *reply;

    connect(&manger,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));

    if(0==nTotalTime)
        return;
    if(strHash.isEmpty())
    {

        strTemp=strTemp.arg(songname);
        request.setUrl(strTemp);

        reply=manger.get(request);

        loop.exec();

        if(reply->error() == QNetworkReply::NoError)
        {
            arrayTemp= reply->readAll();
            jsonDoc=QJsonDocument::fromJson(arrayTemp);
            jsonObj=jsonDoc.object();
            jsonObj = jsonObj.value("data").toObject();
            jsonArray = jsonObj.value("lists").toArray();
            jsonObj= jsonArray.at(0).toObject();
            strHash2= jsonObj.value("FileHash").toString();
        }
        reply->deleteLater();
    }
        strTemp=KGLrcPart1;

        request.setUrl(strTemp.arg(songname).arg(nTotalTime).arg(strHash2));
        //  qDebug() <<"tset1"<<strTemp.arg(songname).arg(nTotalTime).arg(strHash2);
        reply= manger.get(request);
    ///loop1
        loop.exec();
    ////
        if(reply->error() == QNetworkReply::NoError)
        {
            arrayTemp=reply->readAll();
            jsonDoc=QJsonDocument::fromJson(arrayTemp);
            jsonObj=jsonDoc.object();
            jsonArray=jsonObj.value("candidates").toArray();
            jsonObj= jsonArray.at(0).toObject();
            accesskey= jsonObj.value("accesskey").toString();
            strID=jsonObj.value("id").toString();
        }
        reply->deleteLater();

        if (strID == ""){
             emit striderror();

        }
        strTemp=KGLrcPart2;
        request.setUrl(strTemp.arg(strID).arg(accesskey));
          qDebug() <<strTemp.arg(strID).arg(accesskey);
        reply= manger.get(request);
    ///loop2
        loop.exec();
    ///
        if(reply->error()==QNetworkReply::NoError)
        {
                arrayTemp=reply->readAll();
                jsonDoc=QJsonDocument::fromJson(arrayTemp);
                jsonObj=jsonDoc.object();
                arrayTemp="";
                arrayTemp=jsonObj.value("content").toString().toUtf8();
                arrayTemp=QByteArray::fromBase64(arrayTemp);

                if(arrayTemp.size()!=0)
                {
                    emit dolrcworkfinished(arrayTemp,lrcname);//发送做完的信号
                    ////////////////////////////用于保存
                    QFile file(lrcloaction);
                    file.resize(0);
                    if(file.open(QIODevice::WriteOnly))//如果打开失败
                    {
                        file.write(arrayTemp); //write the kugou source krc
                        file.close();
                    }
                }
        }

        reply->deleteLater();
}

