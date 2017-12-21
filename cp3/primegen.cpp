#include<iostream>
#include<cstdio>
#include<cmath> //dependency
#include<cstring>//dependency
using namespace std;
#define M 11111//this number is the end limit of the sieve
bool npr[M];
void genprime(int n){
  int t=sqrt(n)+1;
  npr[0]=npr[1]=false;
  for(int i=2;i<=t;i++)
    for(int j=i+i;j<n;j+=i)npr[j]=false;
}
int main(){
  memset(npr,true,sizeof(npr));
  genprime(M);
  return 0;
}
