#ifndef DBMANAGER_H
#define DBMANAGER_H
#include<QString>
#include<QSqlDatabase>

class DbManager
{
public:
    DbManager(const QString& path);
    bool addNote(QString titolo, QString nota);
    bool delNote(QString titolo, QString nota);
    bool stateChange(QString titolo, QString nota);
private:
    QSqlDatabase mDb;
};

#endif // DBMANAGER_H
