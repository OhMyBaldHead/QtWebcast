#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#define CONN_NAME "myConnection"

class DBHelper
{
public:
    static DBHelper* getInstance();
    void createConn();
    void destoryConn();
    QSqlDatabase getDB();
private:
    QSqlDatabase db;
    static DBHelper* instance;
    DBHelper();
    ~DBHelper();
};

#endif // DBHELPER_H
