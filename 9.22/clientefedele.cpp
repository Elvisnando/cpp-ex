
#include"clientefedele.h"
#include "ritiroPremio.h"

ClienteFedele::ClienteFedele(string nome)
:   Cliente(nome)
,   SC(5)
,   SP(100)
{
    
}

ClienteFedele::ClienteFedele()
:Cliente()
,   SC(5)
,   SP(100)
{

}

double ClienteFedele::spesaTotale()
{
    
    return (Cliente::spesaTotale() - ((SC*Cliente::spesaTotale())/100));

}

void ClienteFedele::aggiungiCarello(Prodotto x)
{
    Cliente::carello.push_back(x);
    
}
void ClienteFedele::accreditaPunti(int i)
{
    puntiAcc = puntiAcc +i;
    if(puntiAcc>=SP) {
        puntiAcc= puntiAcc-SP;
        throw ritiroPremio();
    }

}




