#ifndef MESSAGGIO_H
#define MESSAGGIO_H

#include <QString>

class Messaggio
{
public:
    Messaggio();
    Messaggio(QString tit, QString mess);
    QString getTitle();
    QString getMessage();
    void setStato();

private:
    QString title;
    QString message;
    bool statoDone;


};

#endif // MESSAGGIO_H
