#include "aci.h"

namespace Auto {
    
Aci::Aci()
{
    
}
void Aci::aggiungiAuto(const Automobile& a)
{
    v.push_back(a);

}
int Aci::incassiBolli()
{
    int ris;
    for(Automobile  n : v) {
       ris = ris + n.tassa();
    }
    return ris;

}




    
}