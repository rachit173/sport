//This binary search employs error while number of iterations method
//can also be used
//consider this example of loan payment
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define EPS 1e-9

bool can(double amt,double interest,int mts,double emi){
    if(mts==1){
    if(((amt*(100+interest)/100.00)-emi)>0)
      return false;
    return true;
    }
    if(((amt*(100+interest)/100.00)-emi)<=0)
      return true;
    return can(((amt*(100+interest)/100.00)-emi),interest,mts-1,emi);


}
int main(){
double hi,lo,d,i,v;
lo=0.00;
int m;
scanf("%lf %lf %d",&v,&i,&m);
hi=v*(1+i/50);
while((hi-lo)>EPS){
  d=(hi+lo)/2.0;
  if(can(v,i,m,d)) hi=d;
  else
    lo=d;    
}
  printf("%lf\n",d);
  return 0;
  }

