#include "login.h"
#include "./ui_login.h"
#include "mysql.h"

#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(507, 253);
    ui->user->setEditable(true);
    initConnect();
}

Login::~Login()
{
    delete ui;
}

void Login::initConnect()
{
    // 登录按钮
    connect(ui->btn_login, &QPushButton::clicked, this, [=](){
        QString sql = QString("select * from login where user = '%0' and password = '%1'").arg(ui->user->currentText()).arg(ui->password->text());
        if (mysql::is_qrery_table(sql)) {
            bool flag = true;
            for (int i = 0; i < ui->user->count(); ++i) {
                if (ui->user->currentText() == ui->user->itemText(i)) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ui->user->addItem(ui->user->currentText());
            ui->user->setCurrentText(nullptr);
            ui->password->clear();
			accept();
		} else {
			ui->login_tip->setText("账号或者密码输入不正确，请重新输入");
            ui->password->clear();
		}
    });
}

void Login::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) {
        emit ui->btn_login->clicked();
    }
}
