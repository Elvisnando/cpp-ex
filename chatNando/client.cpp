#include "client.h"
#include "ui_client.h"
#include <QtNetwork>

Client::Client(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::Client)
   , tcpSocket(new QTcpSocket(this))
   , networkSession(Q_NULLPTR)
{
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}
void Client::sessionOpened()
{
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();

        ui->label->setText(tr("This examples requires that you run the "
                                   "Fortune Server example as well."));

       // enableGetFortuneButton();




}
