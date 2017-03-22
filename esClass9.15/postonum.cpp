#include "postonum.h"

Postonum::Postonum()
{

}


Postonum::Postonum(int fila, string nome) 
    :Biglietto(GALLERIA,nome)
    , nfila(fila)
{
}

int Postonum::numeroFila() const
{
    return nfila;
}


