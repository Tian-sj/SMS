#include "login.h"
#include "mysql.h"
#include "main_page.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!mysql::connect_mysql("127.0.0.1", 3306, "root", "123456", "SMS")) {
        QString msg = "数据库打开失败" + mysql::db.lastError().text();
        QMessageBox::information(nullptr, "连接数据库", msg);
        exit(0);
    }

    Login w;
    if (w.exec() == QDialog::Accepted) {
        main_page mp;
		mp.show();
		return a.exec();
	}
}
