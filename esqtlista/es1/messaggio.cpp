#include "messaggio.h"

#include <QString>

Messaggio::Messaggio()
    :title("NULL")
    ,message("NULL")
{

}

Messaggio::Messaggio(QString tit, QString mess)
    :title(tit)
    ,message(mess)
    ,statoDone(false)
{

}

QString  Messaggio::getTitle()
{
    return title;
}

QString Messaggio::getMessage()
{
     return message;

}

void Messaggio::setStato()
{
    statoDone = true;

}
