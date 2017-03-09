#include <iostream>

using namespace std;

struct nodo {
    int n;
    nodo* nextnodo;
};

struct nodoP {
    nodo* info;
    nodoP* nextnodoP;
    
};

nodoP* G(nodoP* L);
nodoP* addNodoP(nodoP* p,nodo*  info);
nodo* addNodo(nodo* p,int num);
void print(nodo* p);
void printA(nodoP* p);
void H(nodoP* A,nodo* &R);

int main () {
    
    nodo* L1 = nullptr;
    nodo* L2 = nullptr;
    nodo* L3 = nullptr;
    nodo* R = nullptr;
    L1 = addNodo(L1,1);
    L1 = addNodo(L1,100);
    L1 = addNodo(L1,3);
    L2 = addNodo(L2,6);
    L2 = addNodo(L2,5);
    L2 = addNodo(L2,7);
    L3 = addNodo(L3,10);
    L3 = addNodo(L3,11);
    L3 = addNodo(L3,12);

    
    nodoP* A = nullptr;
    A = addNodoP(A,L1);
    A = addNodoP(A,L2);
  //  A = addNodoP(A,L3);
   printA(A);
    
  /* nodoP* PR = nullptr;
    PR = G(A);
    printA(PR);*/
 
   H(A,R);
   cout<<"R che ottengo dopo la funzione H: \n";
    print(R);
    
    return 0;
};
int num = 1000000;
nodoP* q=nullptr;
nodoP* G(nodoP* A) {
    
    if(A==nullptr){return q;}
    
    if(A->info==nullptr && A->nextnodoP != nullptr ) {
        A=A->nextnodoP;
         G(A);
        
    } else {
        if(A->nextnodoP == nullptr && A->info != nullptr ) {
            if(A->info->n < num) {
                num = A->info->n;
                q = A;
                
            }   
            return q;
        
        } else {
        
            if(A->info->n < num) {
                num = A->info->n;
                q = A; 
            }
        return q = G(A->nextnodoP);
        }
    }
    
};


nodoP* addNodoP(nodoP* p, nodo* inf) {
nodoP* pa=p;
    if (p == NULL) {
        nodoP* pn = new nodoP;
        pn->info = inf;
        pn->nextnodoP=nullptr;
        return pn;
        
    } else {
        while(p->nextnodoP != nullptr) {
            p=p->nextnodoP;
        }
        nodoP * pn = new nodoP;
        pn->info=inf;
        pn->nextnodoP=nullptr;
        p->nextnodoP=pn;
        
        
        return pa;
    }
}

nodo* addNodo(nodo* p,int num) {
    
    nodo* pa=p;
    if (p == nullptr) {
        nodo* pn = new nodo;
        pn->n = num;
        pn->nextnodo=nullptr;
        return pn;
        
    } else {
        while(p->nextnodo != NULL) {
            p=p->nextnodo;
        }
        nodo * pn = new nodo;
        pn->n=num;
        pn->nextnodo=nullptr;
        p->nextnodo=pn;
        return pa;
    }
    
    
};

void print(nodo* p) {
    
    if( p== NULL) {
        cout<<"Lista Vuota \n";
    } else {
        while(p->nextnodo != NULL) {
            cout<< p->n<<" -> ";
            p=p->nextnodo;  
        }
    cout<< p->n<<" \n";
    }
    
};

void printA(nodoP* p) {
    
    cout<<"La lista A contiene le sotto liste ordinate: \n";
    if( p== NULL) {
        cout<<"Lista Vuota";
    } else {
        while(p->nextnodoP != NULL) {
            print(p->info);
            p=p->nextnodoP;
        }
        print(p->info);
    }
    
};
nodoP* x =nullptr;
nodoP* ar=nullptr;
void H(nodoP* A,nodo* &R) {
    cout<<"PRINT A DOPO modifiche : \t";
    printA(A);
     x = G(A);
    cout<<"out di G(A) su x : \t";
    printA(x);
    
    
    if(x) {
  
        if(x->info->nextnodo != nullptr) {
        R = addNodo(R,x->info->n);
        x->info = x->info->nextnodo;
        H(A,R);
        
      
        } else {
            R = addNodo(R,x->info->n);
            cout<<"SONO QUAAA\n";
            x->info=nullptr;
            
           // x=x->nextnodoP;
          
        }
    } else {
        
        R= nullptr;
    }
         
};



