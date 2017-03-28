
#include "cliente.h"
#include<string>
#include "prodotto.h"

class ClienteFedele : public Cliente {
    
public:
    ClienteFedele();
    ClienteFedele(string nome);
    virtual double spesaTotale();
    void aggiungiCarello(Prodotto x);
    void accreditaPunti(int i);
    int returPuntiAcc();
    
    
private:
    int puntiAcc;
    int SP;
    int SC;
    
    
    
};