#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define oo 1000000009
char s[10000];
int memo[7000][7000];
int n;
int dp(int st,int en){
  if(memo[st][en]!=-1) return memo[st][en];
  if(en-st<1){
    memo[st][en]=0;
    return memo[st][en];
  }
  memo[st][en]=min(min(dp(st,en-1)+1,dp(st+1,en)+1),s[st]==s[en]?dp(st+1,en-1):oo);
  return memo[st][en];
}
int main(){
  int T;
  cin>>T;
  while(T--)
  {
    memset(memo,-1,sizeof(memo));
    cin>>s;
    n=strlen(s);
    cout<<dp(0,n-1)<<endl;
  }
  return 0;
}
