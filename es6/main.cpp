#include <iostream>
using namespace std;




struct nodoA {
    char x;
    nodoA* sx = nullptr;
    nodoA* dx = nullptr;
    
    
};

struct nodoL {
    nodoA* info = nullptr;
    nodoL* nextnodoL = nullptr;
    
};

int  G(nodoA* R, char *P, int dim_P);



nodoL* addNodoL(nodoL* p, nodoA* inf);
nodoA* addNodoA(nodoA* p, char car);
void printL(nodoL* p);
void printA(nodoA* p);
nodoL* F(nodoA* R, char *P, int dim_P);
void addNodol(nodoL* &p, nodoA* N);



int main() {

    
    cout<<"ciao\n";
    char P[2];
    P[0] = 'c';
    P[1] = 'x';
    cout<<P[0]<<"->"<<P[1]<<"\n";
    
   
    
    // riproduco albero del esercizio
    
    nodoA* R = new nodoA;
    R->x = 'x';
    R->sx = new nodoA;
    R->sx->x = 'y';
    R->dx = new nodoA;
    R->dx->x = 'c';
    R->dx->dx=new nodoA;
    R->dx->dx->x = 'x';
    R->dx->sx=new nodoA;
    R->dx->sx->x= 'a';
    R->dx->sx->sx = new nodoA;
    R->dx->sx->sx->x = '0';
    R->dx->dx->dx = new nodoA;
    R->dx->dx->dx->x = 'b';
   // printA(R);
    nodoL* k= nullptr;
    k = F(R,P,1);
    printL(k);
    int a = G(R,P,2);
    cout<<a;
    
    
    
    
return 0;

};

nodoL* addNodoL(nodoL* p, nodoA* inf) {
    
    nodoL* pa=p;
    if (p == NULL) {
        nodoL* pn = new nodoL;
        pn->info = inf;
        pn->nextnodoL=NULL;
        return pn;
        
    } else {
        while(p->nextnodoL != NULL) {
            p=p->nextnodoL;
        }
        nodoL * pn = new nodoL;
        pn->info = inf;
        pn->nextnodoL=nullptr;
        p->nextnodoL=pn;
        return pa;
    }
            
};



void printL(nodoL* p) {
    
    if(p == NULL) {
        cout<<"Lista Vuota \n";
    } else {
        while(p->nextnodoL != NULL) {
            cout<< p->info->x<<" -> ";
            p=p->nextnodoL;  
        }
    cout<< p->info->x<<" \n";
    }
    
};



nodoA* addNodoA(nodoA* p, char car) {
    
    nodoA* init = p;
    if(p == nullptr) {
        p=new nodoA;
        return p;
    } else {
        cout<<"dove vuoi inserire sinistra o destra ? [s][d]: \n";
        
    }
    
};

void printA(nodoA* p) {
    
    if (p==nullptr) {
       
    } else {
        cout<<p->x;
        cout<<"\n";
        printA(p->sx);
        printA(p->dx);
    }
    
};
int c =0;

nodoL * U =nullptr;

nodoL* F(nodoA* R, char *P, int dim_P) {
    if(R == nullptr ) {
           return U;
        
    } else {
        
        if (R->x == P[c]) {
            c++;
            addNodol(U,R);
            F(R->dx,P,dim_P);
            F(R->sx,P,dim_P);
            
        } else {
            
             F(R->dx,P,dim_P);
             F(R->sx,P,dim_P); 
            
            
        }
    }
  //  if (c != dim_P) {return nullptr;}
   
};


void addNodol(nodoL* &p, nodoA* N) {
    
     if(N != nullptr) {
         nodoL* ind = p;
        
         if (p == nullptr) {
           p = new nodoL;
           p->info = N;
        } else {
            while (p->nextnodoL != nullptr) {
                p = p->nextnodoL;
            }
            nodoL * pn = new nodoL;
            pn->info = N;
            pn->nextnodoL = nullptr;
            p->nextnodoL=pn;
            p = ind;
     
        }
    }
        
};

int d;

int  G(nodoA* R, char *P, int dim_P) {
    
    if(R == nullptr ) {
           
        return c ;
        
    } else {
        
        if (R->x == P[c]) {
            c++;
            
             G(R->dx,P,dim_P);
             G(R->sx,P,dim_P);
             
            
        } else {
           // d++;
               G(R->dx,P,dim_P);
               G(R->sx,P,dim_P); 
            
            
            
        }
    }
  
   
};


