
#include"biglietto.h"
#include <string>
using namespace std;


Biglietto::Biglietto()
{

}




Biglietto::COLL Biglietto::retruncol()
{
    return colocazione;
}

string Biglietto::name() const
{
    return nomeaquirente;
}

Biglietto::Biglietto(Biglietto::COLL a,string nome)
{
    colocazione = a;
    nomeaquirente = nome;

}



