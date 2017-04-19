#include "chatconclient.h"
#include "ui_chatconclient.h"
#include <QHostAddress>


ChatConClient::ChatConClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatConClient)


{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onClickButtonInvia()));



}

ChatConClient::ChatConClient(QWidget *parent,QHostAddress ipclient , quint16 porta, QTcpSocket *ss, QUdpSocket *udps ) :
    ChatConClient(parent)
{
    ip = ipclient;
    port = porta;
    s = ss;
    udp = udps;
    QStringList por = ipclient.toString().split(":");
    ip = por.at(3);

    udp->bind(s->localAddress(),s->localPort()+1);
  /*  qDebug()<<"bind a questo ip"<<ip;
    qDebug()<<"bind a questa porta"<<port;*/
    udp->connectToHost(ip,port+1);
    connect(udp,SIGNAL(readyRead()),this,SLOT(connessione()));
   // udp->connectToHost(ip,port+1);







}

ChatConClient::~ChatConClient()
{
    delete ui;
}

void ChatConClient::connessione()
{
    QString mess = udp->readAll();
    ui->textBrowser->append(mess);
    qDebug()<<"ricevo nele ready";
}

void ChatConClient::onClickButtonInvia()
{
    qDebug() << "invio da qui:  " << s->localAddress() << " - " << s->localPort()+1;
    qDebug() << "sending to: " << ip << " - " << port+1;
    udp->write(ui->lineEdit->text().toLatin1());




}
