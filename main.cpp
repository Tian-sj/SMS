#include "login.h"
#include "mysql.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置中文字体
    a.setFont(QFont("Microsoft Yahei", 9));

    //设置中文编码
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
#if _MSC_VER
    QTextCodec* codec = QTextCodec::codecForName("GBK");
#else
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#endif

    if(!mysql::connect_mysql("rm-2zeb530443v74nl6dao.mysql.rds.aliyuncs.com", 3306, "tian_sj", "Tianshiji@2000", "SMS")) {
        QString msg = "数据库打开失败" + mysql::db.lastError().text();
        QMessageBox::information(nullptr, "连接数据库", msg);
        exit(0);
    }

    Login w;
    w.show();
    return a.exec();
}
