#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QHostAddress>
#include <QVariant>
#include <chatconclient.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) ,
    s(new QTcpSocket),
    udps(new QUdpSocket)
{
    ui->setupUi(this);
    connect(s,SIGNAL(connected()),this,SLOT(conessione()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onClickButtoSend()));
    connect(s, SIGNAL(readyRead()), this, SLOT(readyReadd()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onClickItem(QListWidgetItem*)));





}
static inline qint32 ArrayToInt(QByteArray source);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QHostAddress ipserver(ui->lineEdit_2->text());

    nikName = ui->lineEdit_4->text().toUtf8();
    s->connectToHost(ipserver,5500);
    connect(s,SIGNAL(connected()),this,SLOT(connectedd()));

   // connect(this,SIGNAL(dataRecived(QByteArray)),this,SLOT(addDalServer(QByteArray)));

}

void MainWindow::conessione()
{
    qDebug()<<"segnale ricevuto ";

}

bool MainWindow::writeData(QByteArray data)
{
    if(s->state() == QAbstractSocket::ConnectedState)
        {
            s->write(intToArray(data.size())); //write size of data
            s->write(data); //write the data itself
            return s->waitForBytesWritten();
        }
        else
            return false;

}

QByteArray MainWindow::intToArray(qint32 sorce)
{
    QByteArray temp;
        QDataStream data(&temp, QIODevice::ReadWrite);
        data << sorce;
        return temp;

}

void MainWindow::onClickButtoSend()
{

    this->writeData(ui->lineEdit_3->text().toUtf8());

}


void MainWindow::readyReadd()
{

   // ui->textBrowser->clear();
    ui->listWidget->clear();
    QByteArray data = s->readAll();
   // ui->listWidget->addItem(data);
    QString nome;
    QString dato = data;
  //  ui->textBrowser->append(data);
   QStringList mystring = dato.split("\n");
   int c = 0;
   while(c < mystring.size()-1) {
   nome = mystring.at(c);
   qDebug()<< nome;
   ui->listWidget->addItem(nome);
   c++;
   }









}

qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

void MainWindow::addDalServer(QByteArray a)
{

    //ui->textBrowser->append(a);

}

void MainWindow::connectedd()
{
    this->writeData(nikName);
}

void MainWindow::onClickItem(QListWidgetItem* item)
{

    QStringList mystrings;
    mystrings = item->text().split(" ");

    QString port = mystrings.at(2);



    QHostAddress ipserver(mystrings.at(1));

    //s->connectToHost(ipserver,quint16(port.toUInt()));
   // ChatConClient * form = new ChatConClient(0,)
    ChatConClient *form = new ChatConClient(0,ipserver,port.toUShort(),s,udps);
    form->exec();




}

