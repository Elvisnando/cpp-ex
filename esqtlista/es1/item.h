#ifndef ITEM_H
#define ITEM_H

#include "messaggio.h"


#include<QListWidget>

namespace Ui {
class item;
}

class item : public QListWidget
{
    Q_OBJECT

public:
    explicit item(QWidget *parent = 0);
    void ricemes(Messaggio& a);

    ~item();

private:
    Ui::item* ui;
};

#endif // ITEM_H
