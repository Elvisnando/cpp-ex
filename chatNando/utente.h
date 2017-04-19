#ifndef UTENTE_H
#define UTENTE_H
#include <QTcpSocket>


class utente
{
public:
    utente();
    utente(QTcpSocket *ss, QByteArray nikk);
    QTcpSocket* getSoket();
    QByteArray getNikname();
    void setNik(QByteArray nn);


private:
    QTcpSocket *s;
    QByteArray nik;
};

#endif // UTENTE_H
