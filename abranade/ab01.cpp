//this program demonstrates the use of functional pointers
//also the bisection algorithm when the functional value can be evaluated using 
//cpp implementations

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

float rt2(float x){
  return x*x-2;
  }
float rt3(float x){
  return x*x*x-2;
}
float bisection(float xl=0,float xr=100,float e=0.00001,float (*pf)(float x))
//the declaration of functional pointer is worth noting here correct: (*pf)(float x) 
//                                                         incorrect: *pf(float x)
{
  bool xl_is_positive=(*pf)(xl)>0;
  while((xr-xl)>=e){
    float xm=(xl+xr)/2;
    bool xm_is_positive=(*pf)(xm)>0;
    if(xm_is_positive==xl_is_positive)
      xl=xm;
      else
        xr=xm;


  }
  return xl;
}
int main(){
  float y=bisection(&rt2);
  printf("Square Root of 2 is %.5f\n",y);
  y=bisection(1,2,0.00001,&rt3);
  printf("Cube Root of 2 is %.5f\n",y);
  return 0;

}



  


