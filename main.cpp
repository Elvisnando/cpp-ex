
 
#include <iostream>

int divisore(int x, int y);


 
int main()
{
  std::cout << "Ciao inserisci tre numeri interi: " << std::endl;
int x=3;
int y=6;
int z=7;
int ris=0;
int ris1=0;
int ris2=0;
int ris3=0;
int ris4=0;
int ris5=0;




std::cin>>x;
std::cin>>y;
std::cin>>z;




ris= divisore(x,y);
ris1= divisore(x,z);
ris2= divisore(y,x);
ris3= divisore(y,z);
ris4= divisore(z,x);
ris5= divisore(z,y);
if((ris+ris1==2) || (ris2+ris3==2) || (ris4+ris5==2)){
std::cout << "stato A" <<std::endl;

}else
{
if((ris+ris1==1) || (ris2+ris3==1) || (ris4+ris5==1)){

std::cout << "stato B" <<std::endl;
}else{

std::cout << "nessuno dei casi" <<std::endl;
}

}


std::cout << "stati:" << ris<<ris1<<ris2<<ris3<<ris4<<ris5 << std::endl;

    return 0;

}


int divisore(int x, int y){
int ris=0;
int statox=0;
if(x<y) {
ris=y;
while(ris>0){
   ris= ris-x;
   if(ris==0){
       statox =1;
         return statox;
        }
else
{
    if(ris<0) {statox=0; return statox;}
}
}
}else
{
return 0;
}
};

















