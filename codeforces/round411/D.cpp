#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
typedef pair<int,int> ii;
typedef vector<int > vi;
typedef vector<ii> vii;
ll c=1;
ll memo[31];
ll c1=1;
void pre(){
  for(int i=0;i<10000;i++)
    c=(c*2)%mod;
  for(int i=0;i<100;i++)
    c1=(c1*2)%mod;
}
ll R(int m){
  if(m>29){
    ll ans=1;
    ll t=m%10000;
      int x=t%100;
      int y=t/100;
      for(int i=0;i<x;i++)
        ans=((ans*2)%mod);
       for(int i=0;i<y;i++)
         ans=((ans*c1)%mod);
    int times=m/10000;
    for(int i=0;i<times;i++)
      ans=(ans*c)%mod;
      ans=(ans-1+mod)%mod;
      return ans;
  }
  else
      return memo[m];
  
}
int main(){
  string s;
  cin>>s;
  pre();
  for(int i=0;i<31;i++){
    memo[i]=((1<<i)%mod-1+mod)%mod;
  }
  int i=0;
  for(;i<s.size();i++)
    if(s[i]!='b')break;
  int count_a=0;
  ll ans=0;
  for(;i<s.size();i++){
    if(s[i]=='a')
      count_a++;
     else
       ans=(ans+R(count_a))%mod;
  }
  printf("%lld",ans);
  return 0;
}
