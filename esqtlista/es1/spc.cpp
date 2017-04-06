#include "spc.h"
#include "ui_spc.h"
#include "messaggio.h"

Spc::Spc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spc)
{
    ui->setupUi(this);



}


Spc::~Spc()
{
    delete ui;
}

void Spc::onClicKShowButton()
{

}



void Spc::setParam(Messaggio a)
{
    ui->label_2->setText(a.getTitle());
    ui->textBrowser->setText(a.getMessage());

}
