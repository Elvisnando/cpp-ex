#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QHostAddress>
#include <QVariant>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) ,
    s(new QTcpSocket)
{
    ui->setupUi(this);
    connect(s,SIGNAL(connected()),this,SLOT(conessione()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onClickButtoSend()));
    connect(s, SIGNAL(readyRead()), this, SLOT(readyReadd()));


}
static inline qint32 ArrayToInt(QByteArray source);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QHostAddress ipserver(ui->lineEdit_2->text());

    s->connectToHost(ipserver,5500);
    s->waitForConnected(1000);
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
//    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
//    QByteArray *buffer = buffers.value(socket);
//    qint32 *s = sizes.value(socket);
//    qint32 size = *s;


//    while (socket->bytesAvailable() > 0)
//    {
//        buffer->append(socket->readAll());
//        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) // lettura del dato
//        {
//            if (size == 0 && buffer->size() >= 4) //se la lettura è completa
//            {
//                size = ArrayToInt(buffer->mid(0, 4));
//                *s = size;
//                buffer->remove(0, 4);
//            }
//            if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
//            {
//                QByteArray data = buffer->mid(0, size);
//                buffer->remove(0, size);
//                size = 0;
//                *s = size;
//                ui->textBrowser->append(data);
//                emit dataRecived(data);
//            }
//        }
//    }
    ui->textBrowser->clear();
    QByteArray data = s->readAll();
    ui->textBrowser->append(data);


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
