#include <iostream>
#include "disel.h"
#include "benzina.h"
#include "aci.h"
using namespace std;
using namespace Auto;



int main() {
    Diesel* a;
    a = new Diesel(105);
    cout<< a->bollo()<<"\n";
    
    Benzina* b;
    b = new Benzina(1000);
    
    cout<< b->b<<"\n";
    
    
    
    
    Automobile *benzina = new Benzina(1000);
    Automobile *diesel = new Diesel(70);
    Aci * q = new Aci();
    q->aggiungiAuto(*benzina);
    q->aggiungiAuto(*diesel);
    
    
   
    
    
    
    
    
    
    
    return 0;
};
