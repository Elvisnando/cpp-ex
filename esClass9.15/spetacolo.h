#include<iostream>
#include <list>
#include"biglietto.h"

class Spettacolo {

public:
    Spettacolo();
    void aggiungiBiglietto( Biglietto &a);
    list<Biglietto*> ritornaLista() const;
    int posnum();
    double prezzo(Biglietto *a);
    double incasso();
    

private:
    int B;
    int A;
    int nMaxnum;
    int nfilan;
    int contatoreposnum;
    list<Biglietto*> lista;
};
