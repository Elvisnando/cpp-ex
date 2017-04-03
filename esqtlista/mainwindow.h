#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include"form.h"

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

private:
    Ui::MainWindow *ui;
    Dialog* x;
    Form* f;



};

#endif // MAINWINDOW_H
