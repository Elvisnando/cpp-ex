#include"postononnum.h"

Postononnum::Postononnum(Postononnum::prezzo a,Biglietto::COLL b,string nome)
    :Biglietto(b,nome)
    , pr(a)
{
    
}

void Postononnum::stampa()
{
 cout<<"posto non numerato : \n";
}

Postononnum::prezzo Postononnum::ritornaPrezzo()
{
    return pr;

}

