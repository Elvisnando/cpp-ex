#ifndef CHATCONCLIENT_H
#define CHATCONCLIENT_H

#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>
#include <QUdpSocket>

namespace Ui {
class ChatConClient;
}

class ChatConClient : public QDialog
{
    Q_OBJECT

public:
    explicit ChatConClient(QWidget *parent = 0);
    ChatConClient(QWidget *parent, QHostAddress ipclient , quint16 porta, QTcpSocket* ss, QUdpSocket *udps );

    ~ChatConClient();

private:
    Ui::ChatConClient *ui;
    QHostAddress ip;
    quint16 port;
    QTcpSocket *s;
    QUdpSocket *udp;

private slots:
    void connessione();
    void onClickButtonInvia();
    void disconnectSocketUdp();



};

#endif // CHATCONCLIENT_H
