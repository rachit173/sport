#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
   cin>>T;
  long long r;
  for(int i=0;i<T;i++){
  cin>>r;
  long long d=2*r;
  printf("Case %d: %lld.25\n",i+1,d*d);
  }
  return 0;
}
