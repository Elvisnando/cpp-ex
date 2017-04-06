#include "form.h"
#include "ui_form.h"
#include "spc.h"


Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    , g(new Spc)

{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(onPushButton3Clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onPushButton2Clicked()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onPushButtonClicked()));


}

Form::~Form()
{
    delete ui;
}
void Form::insmes(Messaggio a)
{
    mes = a;
    ui->label_2->setText(a.getTitle());
    ui->label->setText(a.getMessage());

   // connect(ui->pushButton_3,SIGNAL(signalShow(Messaggio )),g,SLOT(messArived(Messaggio )));
}


void Form::onPushButton2Clicked()
{
    qDebug("segnale emmesso");

    emit signalDelete();

}

void Form::onPushButtonClicked()
{
    emit signalDone();
}
void Form::onPushButton3Clicked()
{

  // emit signalShow(mes);
    Spc* l= new Spc();
    l->setParam(mes);
    l->exec();
}

Messaggio Form::returnMess()
{
    return mes;
}
