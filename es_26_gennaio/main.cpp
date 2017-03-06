#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void printMatrix(int m[4][5],int R,int K);
void printMatrixBig(int m[5][6],int R,int K);
void controlloBig(int m[5][6],int R,int K);
void controllo(int m[4][5],int R,int K);
int main()
{
int m[4][5];
int mb[4][5];
int ma[5][6];
int value=0;

int r=0;
int c=0;
while(r<4) {
    c=0;
    while(c<5) {
        m[r][c]=0;
        c++;
    }
    r++;
}

r=0;
c=0;
    string line;
    ifstream myfile ("input.txt");
  
    if (myfile.is_open()) {
        while(r<5) {
            c=0;
            while ( getline (myfile,line) && c<6 ) {
                istringstream buffer(line);
                buffer >> value; 
                ma[r][c]=value;
                //cout<<value<<"\n";
                c++;
            }

            r++;
        }
        
        myfile.close();
    }


m[0][3]=2;
m[1][3]=0;
m[2][3]=1;
m[3][3]=0;


m[0][0]=0;
m[0][1]=1;
m[0][2]=0;
m[0][3]=2;
m[0][4]=0;

//printMatrix(m,4,5);
printMatrixBig(ma,5,6);
controlloBig(ma,5,6);
printMatrix(m,4,5);
controllo(m,4,6);

//controllo(m,4,5);
return 0;

};


void printMatrix(int m[4][5],int R,int K){
int r=0;
int c=0;
while(r<R) {
    c=0;
    while(c<K) {
        std::cout<< m[r][c] <<"\t";
        c++;
    }
    std::cout<<"\n";
    r++;
}
std::cout<<"\n";
};

void controllo(int m[4][5],int R,int K) {

int mb[4][5];
int r=0;
int c=0;
int ri=0;
int ci=0;
bool checkn=false;
bool checkr=true;
while(r<R) {
    c=0;
    while(c<K) { 
        ci=0;
        while(ci<K) {
            ri=0;
            while(ri<R) {
             if(m[r][ci] == m[ri][c])
             { checkn=true;} 
             
            ri++;
            }
            checkr= checkn * checkr;
            checkn=false;
            ci++;
        }
        
       m[r][c]=checkr;
        checkr=true; 
        c++;    
    }
    r++; 
   
}

printMatrix(mb,4,5);
    
};

void printMatrixBig(int m[5][6],int R,int K) {
int r=0;
int c=0;
while(r<R) {
    c=0;
    while(c<K) {
        std::cout<< m[r][c] <<"\t";
        c++;
    }
    std::cout<<"\n";
    r++;
}
std::cout<<"\n";

};
void controlloBig(int m[5][6],int R,int K) {
int mb[5][6];
int r=0;
int c=0;
int ri=0;
int ci=0;
bool checkn=false;
bool checkr=true;
while(r<R) {
    c=0;
    while(c<K) { 
        ci=0;
        while(ci<K) {
            ri=0;
            while(ri<R) {
             if(m[r][ci] == m[ri][c])
             { checkn=true;} 
             
            ri++;
            }
            checkr= checkn * checkr;
            checkn=false;
            ci++;
        }
        
         if(checkr==true){mb[r][c]=1;}else {mb[r][c]=0;}
        checkr=true; 
        c++;    
    }
    r++;  
}

printMatrixBig(mb,5,6);
};




