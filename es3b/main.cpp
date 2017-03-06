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

int main () {
    
    nodo* L1 = nullptr;
    nodo* L2 = nullptr;
    nodo* L3 = nullptr;
    L1 = addNodo(L1,3);
    L1 = addNodo(L1,7);
    L1 = addNodo(L1,8);
    L2 = addNodo(L2,2);
    L2 = addNodo(L2,6);
    L2 = addNodo(L2,6);
    L3 = addNodo(L3,1);
    L3 = addNodo(L3,91);
    L3 = addNodo(L3,10001);
  /*    nodo* L4 = nullptr;
    L4 = addNodo(L4,6);
    L4 = addNodo(L4,7);
    L4 = addNodo(L4,8);*/
    
    
    
    
    nodoP* A = nullptr;
    A = addNodoP(A,L1);
    A = addNodoP(A,L2);
    A = addNodoP(A,L3);
  //   A = addNodoP(A,L4);
    printA(A);
    
    nodoP* PR = nullptr;
    PR = G(A);
    printA(PR);
    return 0;
};
int num = 100000;
nodoP* q;
nodoP* G(nodoP* A) {
    
    if(A->nextnodoP == NULL) {
        if(A->info->n < num) {
            num = A->info->n;
            cout<<num<<"\n";
            q = A;
            
        }
       
        return q;
    } else {
        if(A->info->n < num) {
            num = A->info->n;
            cout<<num<<"\n";
            q = A;
            
        }
        G(A->nextnodoP);
    }
    
    
};


nodoP* addNodoP(nodoP* p, nodo* inf) {
nodoP* pa=p;
    if (p == NULL) {
        nodoP* pn = new nodoP;
        pn->info = inf;
        pn->nextnodoP=NULL;
        return pn;
        
    } else {
        while(p->nextnodoP != NULL) {
            p=p->nextnodoP;
        }
        nodoP * pn = new nodoP;
        pn->info=inf;
        pn->nextnodoP=nullptr;
        p->nextnodoP=pn;
        nodo* R = nullptr; // lista di nodi da popolare ordinata 
        
        return pa;
    }
}

nodo* addNodo(nodo* p,int num) {
    
    nodo* pa=p;
    if (p == NULL) {
        nodo* pn = new nodo;
        pn->n = num;
        pn->nextnodo=NULL;
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
        cout<<"Lista Vuota";
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

