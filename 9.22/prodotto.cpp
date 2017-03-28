#include"prodotto.h"

Prodotto::Prodotto()
: prezzoVendita(1)
{

}

Prodotto::Prodotto(int p)
:prezzoVendita(p)
{
    
}

double Prodotto::returnPrezzo()
{
    return prezzoVendita;

}




