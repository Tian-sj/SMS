#include "main_page.h"
#include "ui_main_page.h"

main_page::main_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_page)
{
    ui->setupUi(this);
}

main_page::~main_page()
{
    delete ui;
}

void main_page::on_btn_stocking_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(1);
}

void main_page::on_btn_sales_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(2);
}

void main_page::on_btn_stocks_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(3);
}


void main_page::on_btn_stats_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(4);
}


void main_page::on_btn_daily_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(5);
}


void main_page::on_btn_setting_clicked(bool checked)
{
    if (checked)
        ui->page->setCurrentIndex(6);
}
/*
purchase_and_purchase   // 采购进货
purchase_returns        // 采购退货
accounting              // 往来帐务
purchasing_document_query   // 采购单据查询
current_inventory_query     // 当前库存查询
*/