#include "spetacolo.h"

Spettacolo::Spettacolo()
{
    B=20;
    A=12;
    nfilan=6;
    nMaxnum=112;
    contatoreposnum=0;

}

void Spettacolo::aggiungiBiglietto(const Biglietto& a)
{
    lista.push_back(const_cast<Biglietto*>(&a));
    
    std::cout << "NUMBER OF TICKETS: \n" << lista.size();
    
    for (Biglietto *b : lista) {
        std::cout << "TICKET OWNER : " << b->name() << std::endl;
    }

}

