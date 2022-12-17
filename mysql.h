#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>

class mysql
{
public:
    static QSqlDatabase db;
    static QSqlQueryModel *model;

public:
    mysql(/* args */);
    ~mysql();

public:
    // 连接数据库
    static bool connect_mysql(const QString &Host, const int &Port, const QString &UserName, const QString &Password, const QString &DatabaseName);

    // 查询判断
    static bool is_qrery_table(const QString &);

};

#endif // MYSQL_H