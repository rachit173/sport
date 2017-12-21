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
int memo[1000007];
int k,l;
int dp(int x)
{
  if(x<=0) return 1;
   if(memo[x]!=-1) return memo[x];
   if(x>=1&&dp(x-1)==1) memo[x] = 0;
   else if(x>=k&&dp(x-k)) memo[x]=0;
   else if(x>=l&&dp(x-l)) memo[x]=0;
   else memo[x] = 1;
   return memo[x];
}
int main(){
  int m;
  cin>>k>>l>>m;
  int a[m];
  f(i,m) sc(a[i]);
  string s;
  RESET(memo,-1);
  //f(i,13) cout<<dp(i)<<" ";
  //cout<<endl;
  f(i,m){
    s+=('A'+dp(a[i]));
  }
  cout<<s<<endl;
  return 0;
}
