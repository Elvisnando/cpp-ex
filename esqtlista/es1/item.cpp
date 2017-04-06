#include "item.h"
#include "ui_item.h"
#include "messaggio.h"

item::item(QWidget *parent) :
    QListWidget(parent),
    ui(new Ui::item)
{
    ui->setupUi(this);


}

item::~item()
{
    delete ui;
}

void item::ricemes(Messaggio &a)
{
    ui->lineEdit->text()=a.getTitle();
    ui->lineEdit_2->text()=a.getMessage();
}
