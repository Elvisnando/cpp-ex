#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messaggio.h"
#include "QString"
#include <QListWidgetItem>
#include "form.h"
#include "QListWidget"
#include "QColor"
#include "spc.h"
#include "dbmanager.h"
#include"QDebug"
#include "QWidget"
#include<QSqlQuery>
#include<QSqlRecord>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    x(new Dialog),
    db(new DbManager("/home/elvisnando/es1/note.db"))


{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onPushButtonClicked()));
    connect(x, &Dialog::signalemm, this, &MainWindow::reciveInf);
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onSaveButtonClicked()));

    // carichiamo i dati all' avvio dal DB SqLite
    int c=0;

    QSqlQuery query("SELECT * FROM note");
    QSqlRecord rec = query.record();
    qDebug() << "NUm colonne: " <<rec.count();
    int titoloCol = rec.indexOf("titolo");
    int messCol = rec.indexOf("mess");
    int statoCol = rec.indexOf("stato");
    qDebug()<<titoloCol;


    while(query.next()) {
        int stato = query.value(statoCol).toInt();
        Messaggio mm(query.value(titoloCol).toString(), query.value(messCol).toString());
        Form *asd = new Form();
        asd->insmes(mm);

        connect(asd,&Form::signalDelete,this,&MainWindow::onClickButtoDelete);
        connect(asd,&Form::signalDone,this,&MainWindow::onClickButtonDone);

        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(300, 100));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, asd);
        if(stato == 1) {
            item->setBackground(Qt::green);

        }
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, asd);



    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonClicked()
{
   // x.setModal(true);
   // connect(x,SIGNAL(signalemm(Messaggio)),this,SLOT(reciveInf(Messaggio)));
    x->exec();
}

void MainWindow::reciveInf( Messaggio& m)
{
    int x=0;


    for (int i=0; i < ui->listWidget->count(); i++) {
            QListWidgetItem* itemData = ui->listWidget->item(i);
            QWidget * rr = ui->listWidget->itemWidget(itemData);
            Form * qq = dynamic_cast<Form*>(rr);
            //qDebug()<<qq->returnMess().getTitle();
            if (m.getTitle() == qq->returnMess().getTitle() && m.getMessage() == qq->returnMess().getMessage()) {
                x=1;
            }


        }

    if(x==0) {

    Form *asd = new Form();
    asd->insmes(m);
    connect(asd,&Form::signalDelete,this,&MainWindow::onClickButtoDelete);
    connect(asd,&Form::signalDone,this,&MainWindow::onClickButtonDone);


    // test
    QListWidgetItem *item = new QListWidgetItem;
    item->setSizeHint(QSize(300, 100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, asd);
   // db->addNote(m.getTitle(),m.getMessage());
    } else {
        QMessageBox msgBox;
        msgBox.setText("Nota esiste già !!!!");
        msgBox.exec();

    }
}

void MainWindow::onClickButtoDelete()
{
    qDebug("Segnale ricevuto");
    QListWidgetItem* itemData = (ui->listWidget->currentItem());
    QWidget * rr = ui->listWidget->itemWidget(itemData);
    Form * qq = dynamic_cast<Form*>(rr);
    qDebug()<<qq->returnMess().getTitle();
    db->delNote(qq->returnMess().getTitle(),qq->returnMess().getMessage());


    ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));


}

void MainWindow::onClickButtonDone()
{
    QListWidgetItem* itemData = (ui->listWidget->currentItem());
    QWidget * rr = ui->listWidget->itemWidget(itemData);
    Form * qq = dynamic_cast<Form*>(rr);
    qDebug()<<qq->returnMess().getTitle();

    db->stateChange(qq->returnMess().getTitle(),qq->returnMess().getMessage());


    QColor a(0,255,0,255);
    ui->listWidget->currentItem()->setBackground(a);
}


void MainWindow::onSaveButtonClicked()
{


    for (int i=0; i < ui->listWidget->count(); i++) {
            QListWidgetItem* itemData = ui->listWidget->item(i);
            QWidget * rr = ui->listWidget->itemWidget(itemData);
            Form * qq = dynamic_cast<Form*>(rr);
            qDebug()<<qq->returnMess().getTitle();
            db->addNote(qq->returnMess().getTitle(),qq->returnMess().getMessage());
        }

}


