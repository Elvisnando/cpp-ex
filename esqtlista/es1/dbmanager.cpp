#include "dbmanager.h"
#include "QDebug"
#include<QSqlQuery>
#include<QString>
#include <QSqlError>
#include<QSqlRecord>

DbManager::DbManager(const QString& path)
{
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(path);

    if (!mDb.open())
       {
          qDebug() << "Error: connection with database fail";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }

}
bool DbManager::addNote(QString titolo, QString nota)
{
    bool success = false;
       // you should check if args are ok first...
       QSqlQuery query;
       QSqlQuery query2;

       query2.prepare("SELECT * FROM note WHERE titolo = :titolo AND mess = :nota ");
       query2.bindValue(":titolo",titolo);
       query2.bindValue(":nota",nota);

       if(query2.exec())
       {
           int c=0;
           while(query2.next()) {
           /*QSqlRecord rec = query2.record();
           int ind = rec.indexOf("");
           qDebug() << "Numero rige:  "<<query2.value(ind).toString();*/
               c++;
           }
           qDebug()<<c;
           if(c == 0) {

                query.prepare("INSERT INTO note (titolo, mess, stato) " " VALUES (:titolo, :nota, :stato)");
                query.bindValue(":titolo", titolo);
                query.bindValue(":nota", nota);
                query.bindValue(":stato", 0);
                if(query.exec())
                {
                    success = true;
                }
                else
                {
                    qDebug() << "addPerson error:  ";
                }

           }

       }
       return success;
}

bool DbManager::delNote(QString titolo, QString nota)
{

    QSqlQuery query2;

    query2.prepare("DELETE FROM note WHERE titolo = :titolo AND mess = :nota ");
    query2.bindValue(":titolo",titolo);
    query2.bindValue(":nota",nota);

    if(query2.exec())
    {
        bool success = true;
    }
    else
    {
        qDebug() << "deletet error  ";
    }


}

bool DbManager::stateChange(QString titolo, QString nota)
{
    QSqlQuery query2;

    query2.prepare("UPDATE note SET stato = 1  WHERE titolo = :titolo AND mess = :nota ");
    query2.bindValue(":titolo",titolo);
    query2.bindValue(":nota",nota);

    if(query2.exec())
    {
        bool success = true;
    }
    else
    {
        qDebug() << "deletet error  ";
    }

}


