#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",&a);
#define sc2(a) scanf("%lld",&a);
#define ll long long int
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))

typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll a[10005];
ll memo[10005];
int n;
ll dp(int st){
  if(memo[st]!=-1) return memo[st];
  if(st>=n) return 0;
  memo[st]=max(a[st]+dp(st+2),dp(st+1));
  return memo[st];
}
int main(){
int T;
cin>>T;
for(int t_i=0;t_i<T;t_i++){
  cin>>n;
  for(int i=0;i<n;i++) sc2(a[i]);
  RESET(memo,-1);
  printf("Case %d: %lld\n",t_i+1,dp(0));
}
return 0;
}
