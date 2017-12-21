#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fun(ll bot,char *c){
        ll N=atoi(c);
      int sz=strlen(c);
      ll ad=1;
      for(int i=0;i<sz;i++) ad*=10;
      //cout<<ad<<" "<<N<<endl;
      while(1){
        if(N>bot) break;
        N+=ad;
      }
      return N;
}
int main(){
    int T;
    cin>>T;
    //getchar();
    while(T--){
      //for(int i=0;i<4;i++) getchar();
      char c[16];
      cin>>c;
      //cout<<c;
      ll N;
      int sz=strlen(c);
      ll bot=1988;
      for(int i=sz-1;i>=4;i--){
          bot=fun(bot,&c[i]);
      }
      cout<<bot<<endl;
    }
  return 0;
}
