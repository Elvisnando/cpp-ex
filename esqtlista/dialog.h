#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>
#include"messaggio.h"




class Dialog : public QDialog {

    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    Ui::Dialog *as;

private slots:
 void onPushButtonD();
signals:
 void signalemm( Messaggio& m);


};

#endif // DIALOG_H
