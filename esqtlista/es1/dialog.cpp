#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    as(new Ui::Dialog)
{
    as->setupUi(this);
    connect(as->pushButtonD,SIGNAL(clicked(bool)),this,SLOT(onPushButtonD()));

}
Dialog::~Dialog()
{
     delete as;
}

void Dialog::onPushButtonD()
{
  //  Messaggio me(as->lineEdit->text(),as->lineEdit_2->text());
    Messaggio meq(as->lineEdit_2->text(),as->textEdit->toPlainText());
    emit signalemm(meq);
    as->lineEdit_2->clear();
    as->textEdit->clear();
}


