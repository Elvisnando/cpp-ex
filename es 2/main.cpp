#include <iostream>

int main()
{
  char a='a';
  char b='b';
  char c='c';
int ca=0;
int cb=0;
int cc=0;
char in ='a';
int stato =1;

while(stato ==1){
std::cin>>in;
std::cout<<"inserito: \t"<<in;
std::cout<<"\n";
if(in=='a'){ca++;}
if(in=='b'){cb++;}
if(in=='c'){cc++;}

if(ca==2){stato= 0;std::cout<<"caso A\n";}
if(cb==2){stato= 0;std::cout<<"caso B\n";}
if(ca==1 && cb==1 && cc==1){stato=0;std::cout<<"caso c\n";}

}
return 0;
};
