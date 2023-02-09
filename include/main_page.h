#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QMainWindow>

namespace Ui {
class main_page;
}

class main_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_page(QWidget *parent = nullptr);
    ~main_page();

private slots:
    void on_btn_stocking_clicked(bool checked);     // 进货管理按钮

    void on_btn_sales_clicked(bool checked);        // 销售管理按钮

    void on_btn_stocks_clicked(bool checked);       // 库存管理按钮

    void on_btn_stats_clicked(bool checked);        // 统计报表按钮

    void on_btn_daily_clicked(bool checked);        // 日常管理按钮

    void on_btn_setting_clicked(bool checked);      // 系统设置按钮

private:
    Ui::main_page *ui;
};

#endif // MAIN_PAGE_H
