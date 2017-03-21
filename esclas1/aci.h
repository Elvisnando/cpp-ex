#include "automobile.h"
#include <iostream>
#include <vector>

using namespace std;
namespace Auto {
    
    class Aci  {
        
    public:
        Aci();
        vector<Automobile> v;
       void aggiungiAuto(const Automobile& a);
        int incassiBolli();
        
        
    };
    
}