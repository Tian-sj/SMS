#include "mysql.h"

QSqlDatabase mysql::db = QSqlDatabase::addDatabase("QMYSQL");
QSqlQueryModel *mysql::model = new QSqlQueryModel();

mysql::mysql() {
}

mysql::~mysql() {
    delete model;
    model = nullptr;
}

bool mysql::connect_mysql(const QString &Host, const int &Port, const QString &UserName, const QString &Password, const QString &DatabaseName) {
    db.setHostName(Host);
    db.setPort(Port);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
    if (db.open())
        return true;
    else 
        return false;
}

bool mysql::is_qrery_table(const QString &sql) {
    QSqlQuery query;
    query.exec(sql);
    if (query.size() > 0)
        return true;
    return false;
}
