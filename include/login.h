#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    void initConnect();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
