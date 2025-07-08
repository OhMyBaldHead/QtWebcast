#include "onlinedaoimp.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>

OnlineDaoImp::OnlineDaoImp()
{

}

bool OnlineDaoImp::addOnline(QString& name,int portid)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query(helper->getDB());
    // query.prepare("insert into online(name)values(:name);");
    // query.bindValue(":name", name);
    query.prepare(
        "insert into online(name, portid)values(:name, :portid);");
    query.bindValue(":name", name);
    query.bindValue(":portid", portid);
    bool ret = query.exec();
    if(ret == false){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
        helper->destoryConn();
        return false;
    }
    helper->destoryConn();
    return true;
}

char* OnlineDaoImp::findOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query(helper->getDB());
    query.exec("select name from online;");
    while(query.next()){
        QString username = query.value(0).toString();
        if(username == name){
            static char *pname = username.toLocal8Bit().data();
            helper->destoryConn();
            return pname;
        }
    }
    helper->destoryConn();
    return NULL;
}

bool OnlineDaoImp::delOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query(helper->getDB());
    query.prepare("delete from online where name = :name;");
    query.bindValue(":name", name);
    bool ret = query.exec();
    if(ret == false){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
        helper->destoryConn();
        return false;
    }
    helper->destoryConn();
    return true;
}

vector<QString> OnlineDaoImp::selectOnline()
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query(helper->getDB());
    query.exec("select name from online;");
    while(query.next()){
        QString username = query.value(0).toString();
        onlines.push_back(username);
    }
    helper->destoryConn();
    return onlines;
}

int OnlineDaoImp::getportidOnline(QString& name)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query(helper->getDB());
    if(query.exec("select name,portid from online;")){
        while(query.next()){
            QString username = query.value(0).toString();
            int portid = query.value(1).toInt();
            if(username == name){
                helper->destoryConn();
                return portid;
            }
        }
    }
    else{
        qDebug() << query.lastError().text();
    }
    helper->destoryConn();
    return -1;
}

