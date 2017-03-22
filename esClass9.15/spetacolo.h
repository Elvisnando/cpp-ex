#include<iostream>
#include <list>
#include"biglietto.h"

class Spettacolo {
    
public:
    
    
    Spettacolo();
    void aggiungiBiglietto(const Biglietto &a);
    
private:
    int B;
    int A;
    int nMaxnum;
    int nfilan;
    int contatoreposnum;
    list<Biglietto*> lista;
    
    
    
    
};