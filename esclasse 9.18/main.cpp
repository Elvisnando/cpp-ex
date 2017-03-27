#include<ios>
#include<iosfwd>
#include<fstream>
#include <sstream>  



#include"C.h"

using namespace std;

int main () {
    
    ifstream f("pippo"); 
    ofstream g("mandrake");
    fstream h("pluto") , i("zagon");
    ostream* p = &g;
    stringstream s;
    C c(10);
    c.inser(f); c.inser(g); c.inser(h);
    c.inser(i); c.inser(*p); c.inser(s);
    istream& r=f;
    
    
    
    cout<<"conta: "<<c.conta<istream>(r)<<"\n";
    
    return 0;
};