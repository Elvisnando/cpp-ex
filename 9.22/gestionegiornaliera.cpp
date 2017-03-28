
#include "gestionegiornaliera.h"
#include "cliente.h"
#include "clientefedele.h"


gestioneGiornaliera::gestioneGiornaliera()
{

}


double gestioneGiornaliera::chiudiCassa()
{
    double incassoG;
    for (Cliente* b : lista) {
        
        ClienteFedele *numbered = dynamic_cast<ClienteFedele*>(b);
        if(numbered) {
           incassoG= incassoG + numbered->spesaTotale();
           numbered->accreditaPunti((numbered->spesaTotale()/10));
        } else {
        
        incassoG = incassoG + b->spesaTotale();
        }
 
    }
    return incassoG;
    
};

void gestioneGiornaliera::addCliente(Cliente* c)
{
    lista.push_back(c);

}

int gestioneGiornaliera::saldoPuntiGiornaliero()
{
    int punti =0;
     for (Cliente* b : lista) {
        
        ClienteFedele *numbered = dynamic_cast<ClienteFedele*>(b);
         if(numbered){
             punti = punti + numbered->returPuntiAcc();
        }
    }
    return punti;
        

}


