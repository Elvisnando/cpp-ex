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

private:
    QString title;
    QString message;


};

#endif // MESSAGGIO_H
