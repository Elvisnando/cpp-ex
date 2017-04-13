#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QMessageBox>
#include <QNetworkInterface>
#include<QNetworkSession>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    void sessionOpened();
    ~Server();
public slots:
    void ClientDisconnected();
signals:
    void dataRecived(QByteArray);


private slots:

    void connessioniAttive();
    void readyReadd();
    void shoeData(QByteArray d);



private:
    Ui::Server *ui;
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;

    QHash<QTcpSocket*, QByteArray*> buffers;
    QHash<QTcpSocket*, qint32*> sizes;
    QList<QTcpSocket*> clientSocketList;

};

#endif // SERVER_H
