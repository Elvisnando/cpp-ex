#include <iostream>
#include "automobile.h"
#include "disel.h"
using namespace std;
using namespace Auto;



int main() {
    Diesel* a;
    a = new Diesel(105);
    cout<< a->Bollo()<<"\n";
    
    
    return 0;
};
