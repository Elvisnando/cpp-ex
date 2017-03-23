#include "spetacolo.h"
#include "postonum.h"
#include "postononnum.h"

Spettacolo::Spettacolo()
{
    B=20;
    A=12;
    nfilan=6;
    nMaxnum=112;
    contatoreposnum=0;

}

void Spettacolo::aggiungiBiglietto( Biglietto& a)
{
    
    
    
    
  /*  std::cout << "NUMBER OF TICKETS: \n" << lista.size();
    
    for (Biglietto *b : lista) {
        std::cout << "TICKET OWNER : " << b->name() << std::endl;
    }*/
  Postonum *numbered = dynamic_cast<Postonum*>(&a);
       
       if (numbered && contatoreposnum<= nMaxnum) {
           contatoreposnum++;
           //lista.push_back(const_cast<Biglietto*>(&a));
           lista.push_back(&a);
          
       }
       if(numbered == false){
           lista.push_back(&a);
    }
       
  

}

std::__cxx11::list< Biglietto* > Spettacolo::ritornaLista() const
{
    return lista;

}

int Spettacolo::posnum()
{
    return contatoreposnum;

}
double  Spettacolo::prezzo(Biglietto *a) {
    
    Postonum *numbered = dynamic_cast<Postonum*>(a);
    if(numbered) {
        if(numbered->numeroFila()<=nfilan) {
            return 2*A + 2*B;
        } else {
            return 2*A;
        }
        
    } else {
        double ris;
        Postononnum *number2 = dynamic_cast<Postononnum*>(a);
        if(number2->retruncol() == Biglietto::GALLERIA) {
            ris = B;
        } else {
            ris = B + A;
        }
        if(number2->pr == Postononnum::RIDOTTO) {
            return ris - (A/2);
        } else {
            return ris;
        }
       
    }
    
    
}

double Spettacolo::incasso()
{
    int incas=0;
     for (Biglietto *b : lista) {

       incas = incas + prezzo(b);
}
    return incas;
    

}







