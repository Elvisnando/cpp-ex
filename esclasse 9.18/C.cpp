#include"C.h"
#include<typeinfo>


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
    if(c<nMax && typeid(a) != typeid(stringstream) && typeid(a) != typeid(fstream)) {
    v.push_back(&a);
    c++;
    }

}





