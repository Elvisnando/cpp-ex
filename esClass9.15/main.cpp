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

    Postononnum a(Postononnum::RIDOTTO, Biglietto::GALLERIA, "Marco");
    Postonum a2(112, "Angelo");
    Postononnum a3(Postononnum::INTERO, Biglietto::GALLERIA, "Vicame");

    s->aggiungiBiglietto(a);
    s->aggiungiBiglietto(a2);
    s->aggiungiBiglietto(a3);





    return 0;
    
};
