#include <iostream>



struct nodo {
	int n;
	nodo* nextnodo;
	
};

struct DN {
	nodo* L1=NULL;
	nodo* L2=NULL;
	
};

nodo* addNodo(nodo* p,int num);
void addNodol(nodo* &p,nodo* &N);
void print(nodo* p);
DN S(nodo* L);
void R(nodo* L, nodo* &L1, nodo* &L2);
DN SL(nodo* L);

using namespace std;
int main(int argc, char** argv) {
	
	 nodo* p=NULL;
	 DN f;
	 p = addNodo(p,1);
	 p = addNodo(p,2);
	 p = addNodo(p,3);
	 p = addNodo(p,4);
	 p = addNodo(p,5);
     p = addNodo(p,6);
    // p = addNodo(p,7);
     
     
    
    nodo *L1 = nullptr;
    nodo *L2 = nullptr;
  //  R(p,L1,L2);
    
    
	 print(p);
	/* cout<<"Ultimo nodo dopo il print ciaooo : "<<p->n;
	 cout<<"\n";
	 //f.L1= addNodo(f.L1,6);
	 f=S(p);
	 print(f.L1);
     print(f.L2);
     print(L1);
     print(L2);
     cout<<"\n";*/
    
    /* nodo* lista=nullptr;
     addNodol(lista,L1);
    addNodol(lista,L1);
    addNodol(lista,L1);
    addNodol(lista,L1);
     print((lista));
     print((L1));*/
    DN z;
    
     z= SL(p);
     print(z.L1);
     print(z.L2);
     print(p);
	 
	 
	return 0;
};

nodo* addNodo(nodo* p, int num) {
    
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

DN d;

 DN S(nodo* L) {
 
     if( L->nextnodo == NULL) {	
         return d;
 	} else {
         d.L1 = addNodo(d.L1,L->n);
 	  	L=L->nextnodo;
 		d.L2 = addNodo(d.L2,L->n);
 	    if(L->nextnodo== NULL) {
             return S(L);
 	    } else {
 	        if(L->nextnodo->nextnodo==NULL) {
                 d.L1 = addNodo(d.L1,L->nextnodo->n); //Case in qui L è dispari    
             }
 	    return S(L->nextnodo);
         }	
 	}
 	
 };
 
void R(nodo* L, nodo* &L1, nodo* &L2) {
    if (L->nextnodo == NULL) {
        
    } else {
        L1 = addNodo(L1,L->n);
        L = L->nextnodo;
        L2 = addNodo(L2,L->n);
        
        if(L->nextnodo== NULL) {
           R(L,L1,L2);
        } else {
            if(L->nextnodo->nextnodo==NULL) {
                L1 = addNodo(L1,L->nextnodo->n); //Case in qui L è dispari    
            }
        R(L->nextnodo,L1,L2);
        }
        
    }
    
    
};

 void addNodol(nodo* &p, nodo* &N) {
    
     if(N != nullptr) {
         nodo* ind=p;
        
         if(p == nullptr) {
            p = N;
            N=N->nextnodo;
            p->nextnodo=nullptr;
        
        } else {
            while(p->nextnodo != nullptr) {
                p = p->nextnodo;
            }
        p->nextnodo = N;
        N=N->nextnodo;
        p->nextnodo->nextnodo=nullptr;
        p=ind;
        
        }
    }
        
};

DN w;
DN SL(nodo* L) {
    
    if( L == NULL) {  
        
         return w;
    } else {   
        addNodol(w.L1,L);
        addNodol(w.L2,L);
        
        return SL(L);
          
    }
    
    
};
 
 
