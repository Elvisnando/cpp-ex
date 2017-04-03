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
