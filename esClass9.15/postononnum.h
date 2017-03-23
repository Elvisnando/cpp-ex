#include <iostream>
#include <string>
#include "biglietto.h"
class Postononnum : public Biglietto  {
    
public:
    
    enum prezzo {
        RIDOTTO,
        INTERO
        
    };
    
    Postononnum(prezzo a,COLL b,string nome);
    void stampa();
    prezzo ritornaPrezzo();
    
private:
    prezzo pr;
    
};

