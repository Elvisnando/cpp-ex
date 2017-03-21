#include "benzina.h"

namespace Auto {
    
Benzina::Benzina(int x)
: Automobile(x) {
   if(x<200) {
       b=true;
}
}
int Benzina::bollo()
{
    if(b == true) {
        return tassa()-50;
    } else {
        return tassa();
    }

}




    
};