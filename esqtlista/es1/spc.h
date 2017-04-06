#ifndef SPC_H
#define SPC_H

#include <QWidget>
# include <QDialog>
#include "messaggio.h"

namespace Ui {
class Spc;
}

class Spc : public QDialog
{
    Q_OBJECT

public:
    explicit Spc(QWidget *parent = 0);

    void setParam(Messaggio a);

    ~Spc();

private:
    Ui::Spc *ui;

private slots:
    void onClicKShowButton();

};

#endif // SPC_H
