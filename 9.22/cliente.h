#ifndef CLIENTE_H
#define CLIENTE_H

#include"prodotto.h"


#include<iostream>
#include<vector>


using namespace std;

class Cliente {
    
public:
    Cliente();
    Cliente(string name);
   virtual double spesaTotale();
     void aggiungiAlCarello(Prodotto x);
      ~Cliente();
    
private:
    string nome;
protected:
    vector<Prodotto> carello;
    
    
    
};

#endif 