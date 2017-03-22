#include <iostream>
#include"biglietto.h"

class Postonum : public Biglietto  {
    
public:
    Postonum();
    Postonum(int fila, string nome);

    int numeroFila() const;

private:
    int nfila;
};
