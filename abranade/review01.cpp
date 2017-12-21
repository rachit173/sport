#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
template <class T>
T sum(const T &a,const T &b){
  if(a<=0||b<=0)
    throw "All parameters should be greater than 0.";
  return a+b;
}
int main(){
  float a,b;
  cin>>a>>b;
  try{
  printf("%lf",sum(a,b));
  }
  catch(char *e){
    cout<<"All  parameters must be greater than 0";
    return 1;
  }
  return 0;
}
