#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include"form.h"
#include "spc.h"
#include "dbmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void onPushButtonClicked();
    void reciveInf( Messaggio& m);
    void onClickButtoDelete();
    void onClickButtonDone();




    void onSaveButtonClicked();

private:
    Ui::MainWindow *ui;
    Dialog* x;
    DbManager* db ;
    int titoloCol;




};

#endif // MAINWINDOW_H
