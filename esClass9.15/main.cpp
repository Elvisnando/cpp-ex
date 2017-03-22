#include <iostream>
#include"postonum.h"
#include"postononnum.h"
#include "spetacolo.h"

using namespace std;

int main() {
    
//    Biglietto *a= new Postonum(2,"MArco");
//    Biglietto* a2= new Postonum(2,"MArco4");
//    Biglietto* a3= new Postonum(2,"MArco5");
   Biglietto* b= new Postononnum(Postononnum::RIDOTTO,Biglietto::GALLERIA,"ALEANDO");
   Spettacolo* s = new Spettacolo();
   
   
   Biglietto a(Biglietto::GALLERIA, "Marco");
   Biglietto a2(Biglietto::GALLERIA, "Angelo");
   Biglietto a3(Biglietto::GALLERIA, "Vicame");
   Biglietto r(2,"Africano");
   
   
    s->aggiungiBiglietto(a);
     s->aggiungiBiglietto(a2);
      s->aggiungiBiglietto(a3);
//     s->aggiungiBiglietto(a2);
//     s->aggiungiBiglietto(a3);
    
     cout<<b->retruncol();
    return 0;
    
};