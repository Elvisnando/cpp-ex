#include "server.h"
#include "ui_server.h"
#include "QNetworkConfigurationManager"
#include"QSettings"
#include "QNetworkSession"
#include <QTcpSocket>

static inline qint32 ArrayToInt(QByteArray source);

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
    , tcpServer(Q_NULLPTR)
    , networkSession(0)
{
    ui->setupUi(this);
    this->sessionOpened();
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(connessioniAttive()));
   // connect(tcpServer,SIGNAL(dataRecived(QByteArray)),this,SLOT(shoeData(QByteArray)));



}

Server::~Server()
{
    delete ui;
}



void Server::sessionOpened()
{
    // Save the used configuration
       if (networkSession) {
           QNetworkConfiguration config = networkSession->configuration();
           QString id;
           if (config.type() == QNetworkConfiguration::UserChoice)
               id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
           else
               id = config.identifier();

           QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
           settings.beginGroup(QLatin1String("QtNetwork"));
           settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
           settings.endGroup();
       }

       tcpServer = new QTcpServer(this);
       if (!tcpServer->listen(QHostAddress::Any,5500)) {
           QMessageBox::critical(this, tr("Fortune Server"),
                                 tr("Unable to start the server: %1.")
                                 .arg(tcpServer->errorString()));
           close();
           return;
       }
       QString ipAddress;
       QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
       // use the first non-localhost IPv4 address
       for (int i = 0; i < ipAddressesList.size(); ++i) {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               ipAddress = ipAddressesList.at(i).toString();
               break;
           }
       }
       // if we did not find one, use IPv4 localhost
       if (ipAddress.isEmpty())
           ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
       ui->label->setText(tr("Server is running on\n\nIP: %1\nport: %2\n")
                            .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Server::connessioniAttive()

{
    qDebug()<<"Ricevuto";
   // ui->textBrowser->setText("Connessione");

    while (tcpServer->hasPendingConnections())
    {
        qDebug()<<"c'è la connesione";


        QTcpSocket *socket = tcpServer->nextPendingConnection();
        clientSocketList.push_back(socket);


        QString m = "ciao";
        foreach (QTcpSocket *w, clientSocketList) {
            foreach (QTcpSocket *p, clientSocketList) {
                m = p->peerAddress().toString();
                w->write(m.toLatin1()+ " " + m.number(p->peerPort()).toLatin1()+"\n");
               // w->write(m.number(p->peerPort()).toLatin1());
               // w->write("\n");
            }
        }

        int a = socket->peerPort();
        ui->textBrowser->append(socket->localAddress().toString()+ " "+ socket->localPort());
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyReadd()));
        qDebug()<<" la porta è:  "<<socket->peerPort();

        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);
        buffers.insert(socket, buffer);
        sizes.insert(socket, s);

        connect(socket, &QTcpSocket::disconnected, this, &Server::ClientDisconnected);



    }




}

void Server::readyReadd()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    qint32 size = *s;
    while (socket->bytesAvailable() > 0)
    {
        buffer->append(socket->readAll());
        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) // lettura del dato
        {
            if (size == 0 && buffer->size() >= 4) //se la lettura è completa
            {
                size = ArrayToInt(buffer->mid(0, 4));
                *s = size;
                buffer->remove(0, 4);
            }
            if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
            {
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                *s = size;
                ui->textBrowser->append(data);
                emit dataRecived(data);

            }
        }

    }
socket->write("ciockkodcko");

}


qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

void Server::shoeData(QByteArray d)
{

    ui->textBrowser->setText(d);

}

void Server::ClientDisconnected()
{
    QTcpSocket* pClient = static_cast<QTcpSocket*>(QObject::sender());
    clientSocketList.removeOne(pClient);
    qDebug() << "ci siamo disconessi ";
    QString m = "ciao";
    foreach (QTcpSocket *w, clientSocketList) {
        foreach (QTcpSocket *p, clientSocketList) {
            m = p->peerAddress().toString();
            w->write(m.toLatin1()+ " " + m.number(p->peerPort()).toLatin1()+"\n");
           // w->write(m.number(p->peerPort()).toLatin1());
           // w->write("\n");
        }
    }

}
