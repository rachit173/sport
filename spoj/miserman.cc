#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d",a)
#define sc1(a) scanf("%lld",&a)
#define pf1(a) printf("%lld",a)
#define sc2(a) scanf("%d %d",&a.first,&a.second)
#define br printf("\n")
#define sp printf(" ")
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,st,n) for(int i=st;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod 1000000007
#define mod1 1000000009
#define oo 1000000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int grid[101][101];
int memo[101][101];
int n,m;
int dp(int city,int bus){
  if(city>=n) return 0;
  if(bus<0||bus>=m) return 100000;
  if(memo[city][bus]!=-1) return memo[city][bus];
  memo[city][bus]  = grid[city][bus] + min(dp(city+1,bus),min(dp(city+1,bus+1),dp(city+1,bus-
  1)));   
  return memo[city][bus];
}
int main(){
  cin>>n>>m;
  f(i,n) f(j,m) sc(grid[i][j]);
  RESET(memo,-1);
  int mn = 1000000;
  f(i,m) mn = min(mn,dp(0,i));
  cout<<mn<<endl;

return 0;
}
