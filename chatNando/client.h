#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QDataStream>
#include <QNetworkSession>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    void sessionOpened();

private:
    Ui::Client *ui;
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
};

#endif // CLIENT_H
