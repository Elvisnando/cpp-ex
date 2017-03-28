
#include<vector>
#include"cliente.h"
class gestioneGiornaliera {
    
public:
    gestioneGiornaliera();
    double chiudiCassa();
    void addCliente(Cliente* c);
    int saldoPuntiGiornaliero();
    
private:
    vector<Cliente*> lista;
    
};