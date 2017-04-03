#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messaggio.h"
#include "QString"
#include <QListWidgetItem>
#include "form.h"
#include "QListWidget"
#include "QColor"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    x(new Dialog),
    f(new Form)

{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onPushButtonClicked()));
    connect(x, &Dialog::signalemm, this, &MainWindow::reciveInf);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonClicked()
{
   // x.setModal(true);
   // connect(x,SIGNAL(signalemm(Messaggio)),this,SLOT(reciveInf(Messaggio)));
    x->exec();
}

void MainWindow::reciveInf( Messaggio& m)
{
    Form *asd = new Form(this);
    asd->insmes(m);
    connect(asd,&Form::signalDelete,this,&MainWindow::onClickButtoDelete);
    connect(asd,&Form::signalDone,this,&MainWindow::onClickButtonDone);

    // test
    QListWidgetItem *item = new QListWidgetItem;
    item->setSizeHint(QSize(300, 100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, asd);
}

void MainWindow::onClickButtoDelete()
{
    qDebug("Segnale ricevuto");

    ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));

}

void MainWindow::onClickButtonDone()
{
    QColor a(0,255,0,255);

    ui->listWidget->currentItem()->setBackground(a);

}

