
#include"cliente.h"


Cliente::Cliente()
: nome("Genericoo")
{
    
}

Cliente::Cliente(string name)
{
    nome = name;

}

  double Cliente::spesaTotale()
{
    int c=0;
    for(Prodotto b : carello) {
        c = c + b.returnPrezzo();
    }
    return c;

}

void Cliente::aggiungiAlCarello(Prodotto x)
{
    carello.push_back(x);

}
Cliente::~Cliente()
{
    

}





