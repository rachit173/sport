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
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,st,n) for(int i=st;i<n;i++)
#define f3(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
//BIT implementation for sum of numbers in a subarray
ll a[1000005];
ll Bit[1000007];
int n;
void update(ll val,int x){
  for(;x<=n;x+=(x&(-x))) Bit[x]+=val;
}
ll search(int x,int cf){
  if(x<1) return 0;
  int x1=x-(x&(-x))+1;
  cf+=(x&(-x));
  cout<<x<<" "<<Bit[x]<<" "<<cf<<endl;
  return Bit[x]*cf+search(x1-1,cf);
}
int main(){
cin>>n;
RESET(Bit,0);
RESET(a,0);
  f2(i,1,n+1) sc1(a[i]);  //scanning the input 
f2(i,1,n+1) update(a[i],i),update(-a[i],i+1); //constructing the BIT tree
int q;      //q is the number of queries
sc(q);
int t;int u,v;
ll val;
// 0 stands for search and 1 for update
f(i,q){
  sc(t);
  if(t==0){
    sc(u);sc(v);
    pf1(search(v,0)-search(u-1,0));br;
    }
    else{
      sc(u);sc(v);sc1(val);
      update(val,u);update(-val,v+1);
    }
}
return 0;
}
