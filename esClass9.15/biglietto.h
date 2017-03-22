
#ifndef BIGLIETTO_H
#define BIGLIETTO_H


#include <iostream>
#include <string>
using namespace std;


class Biglietto {
    
public:
    
    enum COLL  {
        
        PLATEA,
        GALLERIA
        
    };
    
    Biglietto();
    Biglietto(COLL a, string nome);
    Biglietto::COLL retruncol();
    std::string name() const;
    
private:
    
    string nomeaquirente;
    COLL colocazione;
    
    
};

#endif 