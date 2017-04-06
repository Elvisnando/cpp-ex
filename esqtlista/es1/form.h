#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>


#include"messaggio.h"
#include "spc.h"

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    Messaggio returnMess();
    ~Form();

   void insmes(Messaggio a);

private slots:
   void onPushButton2Clicked();
   void onPushButtonClicked();
   void onPushButton3Clicked();

private:
    Ui::Form *ui;
    Messaggio mes;
    Spc* g;
signals:
    void signalDelete();
    void signalDone();
    void signalShow(Messaggio a);
};

#endif // FORM_H
