#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    server(new Server),
    client(new Client)
{
    ui->setupUi(this);


    server->show();

    //client->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
