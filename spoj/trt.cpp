#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sc1(a) scanf("%lld",&a);
#define pf1(a) printf("%lld",a);
#define sc2(a) scanf("%d %d",&a.first,&a.second);
#define br printf("\n");
#define sp printf(" ");
#define ll long long int
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll trt[3000];
int n;
ll memo[3000][3000];
ll dp(int st,int en){
  if(memo[st][en]!=-1) return memo[st][en];
  ll age=n-(en-st);
  if(st==en){
    memo[st][en]=age*trt[st];
    return memo[st][en];
  }
  memo[st][en]=max(trt[st]*age+dp(st+1,en),trt[en]*age+dp(st,en-1));
  return memo[st][en];
}
int main(){
  sc(n);
  f(i,n) sc1(trt[i]);
  RESET(memo,-1);
  pf1(dp(0,n-1));br;
return 0;
}
