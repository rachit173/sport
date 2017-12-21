//function templates
//in this example it is used with the absolute value function 
//this is used for both int and float datatypes
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
template<typename T>
T Abs(T x){
  if(x>0)
    return x;
    else return -x;
}

int main(){
  int x=-3;
  float y=-4.56;
  double z=-5.678933434434;
  cout<<Abs(x)<<" "<<Abs(y)<<"\n";
  printf("%lf\n",Abs(z));
  return 0;
}


