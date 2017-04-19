#include "utente.h"

utente::utente()
{

}

utente::utente(QTcpSocket *ss, QByteArray nikk) :
    s(ss) ,
    nik(nikk)
{

}

QTcpSocket* utente::getSoket()
{
    return s;
}

 QByteArray utente::getNikname()
 {
     return nik;
 }

 void utente::setNik(QByteArray nn)
 {
     nik =nn;
 }
