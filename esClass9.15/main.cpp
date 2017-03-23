#include <iostream>
#include"postonum.h"
#include"postononnum.h"
#include "spetacolo.h"

using namespace std;

int main() {
    
//    Biglietto *a= new Postonum(2,"MArco");
//    Biglietto* a2= new Postonum(2,"MArco4");
//    Biglietto* a3= new Postonum(2,"MArco5");
//     Postonum* b = new Postononnum(Postononnum::RIDOTTO,Biglietto::GALLERIA,"ALEANDO");
    Spettacolo* s = new Spettacolo();

    Postononnum a(Postononnum::RIDOTTO, Biglietto::PLATEA, "Marco");
    Postonum a2(112, "Angelo");
    Postonum a4(189, "settembre");
    Postononnum a3(Postononnum::INTERO, Biglietto::GALLERIA, "Vicame");
    Postononnum a5(Postononnum::INTERO, Biglietto::GALLERIA, "dado");

    s->aggiungiBiglietto(a);
    s->aggiungiBiglietto(a2);
    s->aggiungiBiglietto(a3);
    s->aggiungiBiglietto(a4);
    s->aggiungiBiglietto(a5);
   /* cout<<s->posnum()<<"\n";
    cout<<s->prezzo(&a)<<"\n";*/
    cout<<s->incasso()<<"\n";
   /**
    * nel main funciton mi fai l'output del nome di tutti gli acquirenti dei biglietti assieme al numero fila
    * 
    * e il numero fila lo moltiplichi per 123 e mi stampi il risultato
    */
   //list<Biglietto*> lista = s->ritornaLista();
    return 0;
    
};
