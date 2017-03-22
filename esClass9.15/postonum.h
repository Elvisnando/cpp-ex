#include <iostream>
#include"biglietto.h"

class Postonum : public Biglietto  {
    
public:
    int nfila;
    Postonum();
    Postonum(int fila, string nome);
    
    
};