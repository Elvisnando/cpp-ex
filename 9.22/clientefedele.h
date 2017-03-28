
#include "cliente.h"
#include<string>
#include "prodotto.h"

class ClienteFedele : public Cliente {
    
public:
    ClienteFedele();
    ClienteFedele(string nome);
    double spesaTotale();
    void aggiungiCarello(Prodotto x);
    void accreditaPunti(int i);
    
    
    
private:
    int puntiAcc;
    int SP;
    int SC;
    
    
    
};