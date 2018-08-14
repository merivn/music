#include "database.h"

database::database()
{

}

database::~database()
{

}
//建立一个数据库连接
bool database::createConnection()
{
    //以后就可以用"sqlite1"与数据库进行连接了
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
    db.setDatabaseName(".//database//qtDb.db");
    if( !db.open())
    {
        qDebug() << "无法建立数据库连接";
        return false;
    }
    return true;
}

//创建数据库表
bool database::createTable()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
//    bool success = query.exec("create table automobil(id int primary key,attribute varchar,"
//                              "type varchar,kind varchar,nation int,carnumber int,elevaltor int,"
//                              "distance int,oil int,temperature int)");

//    musicname
//    musicalbum
//    musichash
//    musicdur
//      id
    bool success = query.exec("create table cmusic(musicname varchar(40) primary key,"
                              "musichash varchar(40),musicdur varchar(20), musicalbum varchar(20))");
//    bool success = query.exec("create table cmusic(id int primary key, musicname varchar,"
//                              "musichash varchar,musicdur varchar, musicalbum varchar");
    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("数据库表创建失败！");
        return false;
    }
}

//向数据库中插入记录
bool database::insert()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into cmusic values(?, ?, ?, ?,?)");

    long records = 2;
    for(int i=0; i<records; i++)
    {
        query.bindValue(0, i);
        query.bindValue(1, "张杰 - 天下 (2009张杰穿越人海北京演唱会)");
        query.bindValue(2, "8310DD21F4DC1AD1AA77A78B26E57B03");
        query.bindValue(3, "89898989898");
        query.bindValue(4, "");
        bool success=query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
            return false;
        }
    }
    return true;
}
//      id
//    musicname
//    musichash
//    musicdur
//    musicalbum
bool database::insertm(const QString musicname,const QString musichash\
                       ,const QString musicdur,const QString musicalbum)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into cmusic values(?, ?, ?, ?)");

//    long records = 2;
//    int sum = tablecount();
//    qDebug()<<sum;
//    for(int i=sum-1; i<records; i++)
//    {
//        query.bindValue(0, sum);
        query.bindValue(0, musicname);
        query.bindValue(1, musichash);
        query.bindValue(2, musicdur);
        query.bindValue(3, musicalbum);
        bool success=query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
            return false;
        }
//    }
    return true;
}

//查询所有信息
bool database::queryAll()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from cmusic");
    QSqlRecord rec = query.record();
    while(query.next())
    {
        for(int index = 0; index < rec.count(); index++)
            qDebug() << query.value(index) << " ";
    }
}
bool database::readAll(QStringList &col_name,QStringList &col_hash,QStringList &col_dur)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from cmusic");
//    QSqlRecord rec = query.record();
    while(query.next())
    {
//        for(int index = 0; index < rec.count(); index++){
          col_name.append(query.value(0).toString());
          col_hash.append(query.value(1).toString());
          col_dur.append(query.value(2).toString());
//            qDebug() << query.value(index) << " ";
//        }
    }
}


//QStringList col_name;
//QStringList col_hash;
//QStringList col_dur;


int database::tablecount(const QString tablename){
    QSqlDatabase db = QSqlDatabase::database("sqlite1");
    QSqlQuery query(db);
    QString tempcmd = "select count(musicname) from cmusic";
    query.exec(tempcmd);
    int i;
    while(query.next())
    {
        i= query.value(0).toLongLong();
    }
    return i;
}

//根据ID删除记录
bool database::deleteById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("delete from automobil where id = %1").arg(id));
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    return true;
}

//根据歌名删除记录
bool database::deleteByname(const QString musicname)
{

    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    QString tempcmd = QString("delete from cmusic where musicname = '%1'").arg(musicname);
 //   qDebug() << musicname <<tempcmd;
    query.prepare(tempcmd);
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    return true;
}

//根据ID更新记录
bool database::updateById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare(QString("update automobil set attribute=?,type=?,"
                             "kind=?, nation=?,"
                             "carnumber=?, elevaltor=?,"
                             "distance=?, oil=?,"
                             "temperature=? where id=%1").arg(id));

     query.bindValue(0,"四轮");
     query.bindValue(1,"轿车");
     query.bindValue(2,"富康");
     query.bindValue(3,rand()%100);
     query.bindValue(4,rand()%10000);
     query.bindValue(5,rand()%300);
     query.bindValue(6,rand()%200000);
     query.bindValue(7,rand()%52);
     query.bindValue(8,rand()%100);

     bool success=query.exec();
     if(!success)
     {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
     }
    return true;
}

//排序
bool database::sortById()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    bool success=query.exec("select * from automobil order by id desc");
    if(success)
    {
        qDebug() << QObject::tr("排序成功");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("排序失败！");
        return false;
    }
}
