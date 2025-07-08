#include "dbhelper.h"
#include <QDebug>

DBHelper* DBHelper::instance = nullptr;

DBHelper* DBHelper::getInstance()
{
    if (!instance) {
        instance = new DBHelper();
    }
    return instance;
}

DBHelper::DBHelper()
{
    // 构造函数中不初始化连接，延迟到createConn()
    db = QSqlDatabase::addDatabase("QSQLITE",CONN_NAME);
    db.setDatabaseName("user.db");
    db.open();
    QString dropTable = "DROP TABLE IF EXISTS online";
    QString createtb_user = "CREATE TABLE IF NOT EXISTS tb_user ("
                        "name TEXT NOT NULL UNIQUE, "  // name字段：非空且唯一
                        "passwd TEXT NOT NULL)";     // password字段：非空

    QString createonline = "CREATE TABLE IF NOT EXISTS online ("
                        "name TEXT NOT NULL UNIQUE, "
                        "portid INT NOT NULL)";          // password字段：非空
    QSqlQuery query(db); // 绑定当前数据库连接
    query.exec(dropTable);
    query.exec(createtb_user);
    query.exec(createonline);

    // 查询SQLite系统表获取所有表名连接
    if (query.exec("SELECT name FROM sqlite_master WHERE type='table'")) {
        while (query.next()) {
            QString tableName = query.value(0).toString();
            qDebug() << tableName ;
        }
    }
    db.close();
}

void DBHelper::createConn()
{
    // 创建新连接
    db.open();
    //qDebug() << "数据库连接成功";
}

void DBHelper::destoryConn()
{
    db.close();
    //qDebug() << "数据库断开连接";
}


// 添加析构函数释放单例
DBHelper::~DBHelper()
{
    destoryConn();
    db.removeDatabase("user.db");
}

QSqlDatabase DBHelper::getDB(){
    return db;
}
