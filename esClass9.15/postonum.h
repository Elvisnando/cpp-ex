#include <iostream>
#include"biglietto.h"

class Postonum : public Biglietto  {
    
public:
    Postonum();
    Postonum(int fila, string nome);
    void stampa();

    int numeroFila() const;

private:
    int nfila;
};
