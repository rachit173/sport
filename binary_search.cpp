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
int main(){
int N,Q;
cin>>N>>Q;
ll a[N];
f1(i,1,N+1) sc(a[i]);
ll query;
while(Q--){
  sc1(query);
  int lower = 1;
  int upper = N;
  while(lower<upper){
    middle = (lower + upper)/2;
    if(x>a[middle]) lower = middle + 1;
    else
      upper = middle;
  }
  if(query==a[lower]) pf(lower);
  else pf(-1);
  br;
}
return 0;
}
