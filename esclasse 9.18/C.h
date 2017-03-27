
#include<vector>
#include<ios>
#include<iosfwd>
#include<fstream>
#include <sstream>
#include<iostream>

using namespace std;
class C {
    
public:
    C();
    C(int max);
    void inser(ios& a);
    
    template <class T>
    int conta( T& t) {
        int c=0;
    for (ios* b : v) {
        if (dynamic_cast<T*>(b)) {
            c++;
        }
        
    }
    return c;
    }
    
    
    
private:
    int nMax;
    vector<ios*> v;
    int c=0;
    
};