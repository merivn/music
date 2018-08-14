#ifndef DATABASE_H
#define DATABASE_H

#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>


class database
{
public:
    database();
    ~database();
    bool createConnection();  //创建一个连接
    bool createTable();       //创建数据库表
    bool insert();            //出入数据
    bool queryAll();          //查询所有信息
    bool updateById(int id);  //更新
    bool deleteById(int id);  //删除
    bool sortById();          //排序
    int tablecount(const QString = "");
    bool insertm(const QString musicname,const QString musichash\
                           ,const QString musicdur,const QString musicalbum = "");
    bool deleteByname(const QString musicname);
    bool readAll(QStringList &col_name,QStringList &col_hash,QStringList &col_dur);
};

#endif // DATABASE_H
