#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}
void Form::insmes(Messaggio a)
{
    ui->label_2->setText(a.getTitle());
    ui->label->setText(a.getMessage());
}


void Form::on_pushButton_2_clicked()
{
    qDebug("segnale emmesso");

    emit signalDelete();

}

void Form::on_pushButton_clicked()
{
    emit signalDone();
}
