#include"C.h"

C::C()
    :nMax(10)
{
}


C::C(int max)
    :nMax(max)
{
}

void C::inser(ios& a)
{
    if(c<nMax) {
    v.push_back(&a);
    c++;
    }

}

template<class T> 
int C::conta(T& t) const
{
    int c=0;
    for (ios* b : v) {
        if (dynamic_cast<T*>(*b)) {
            c++;
        }
        
    }
    return c;

};



