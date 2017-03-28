
#include<iostream>
#include <stdexcept>
#include <limits>


#include"prodotto.h"
#include"cliente.h"
#include "clientefedele.h"
#include "ritiroPremio.h"
#include"gestionegiornaliera.h"

using namespace std;

int main () {
    
    Prodotto uovo(20);
    Prodotto pane;
    Prodotto carne(12);
    Cliente c1("Elvis");
    c1.aggiungiAlCarello(uovo);
    c1.aggiungiAlCarello(pane);
    c1.aggiungiAlCarello(carne);
    
    ClienteFedele c2("endrit");
    c2.aggiungiAlCarello(uovo);
    c2.aggiungiAlCarello(pane);
    c2.aggiungiAlCarello(carne);
    
    cout<<c1.spesaTotale()<<"\n"; 
    cout<< c2.spesaTotale()<<"\n";
    
    gestioneGiornaliera g;
    g.addCliente(&c1);
    g.addCliente(&c2);
    cout<<g.chiudiCassa()<<endl;
    cout<<g.saldoPuntiGiornaliero()<<endl;
    
   return 0;
};