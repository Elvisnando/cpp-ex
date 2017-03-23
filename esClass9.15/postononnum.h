#include <iostream>
#include <string>
#include "biglietto.h"
class Postononnum : public Biglietto  {
    
public:
    
    enum prezzo {
        RIDOTTO,
        INTERO
        
    };
    prezzo pr;
    Postononnum(prezzo a,COLL b,string nome);
    void stampa();
    
    
};

