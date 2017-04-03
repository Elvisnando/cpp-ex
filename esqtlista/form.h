#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>


#include"messaggio.h"

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

   void insmes(Messaggio a);

private slots:
   void on_pushButton_2_clicked();

   void on_pushButton_clicked();

private:
    Ui::Form *ui;
signals:
    void signalDelete();
    void signalDone();
};

#endif // FORM_H
