#include <iostream>
#include "disel.h"
#include "benzina.h"
using namespace std;
using namespace Auto;



int main() {
    Diesel* a;
    a = new Diesel(105);
    cout<< a->Bollo()<<"\n";
    
    Benzina* b;
    b = new Benzina(1000);
    
    cout<< b->b<<"\n";
    
    
    
    
    Automobile *benzina = new Benzina(1);
    Automobile *diesel = new Diesel(1);
   
    
    
    
    
    
    
    
    return 0;
};
