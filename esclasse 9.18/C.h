#include<iostream>
#include<vector>
using namespace std;
class C {
    
public:
    C();
    C(int max);
    void inser(ios& a);
    template <class T>
    int conta(T& t) const;
    
    
    
private:
    int nMax;
    vector<ios*> v;
    int c=0;
    
};