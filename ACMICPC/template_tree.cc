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
#define MAXN 500005
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int a[MAXN];
vi g[MAXN];
int pos[MAXN],to[MAXN];
int w[MAXN];
int kw = 0;   
void dfs(int x,int pr){
  pos[x] = kw;
  w[kw++] = x;  //store key(x) or weight(a[x]) 
  for(int i=0;i<(int)g[x].size();i++){
    if(g[x][i]!=pr){
      dfs(g[x][i],x);
    }
  }
  to[x] = kw-1;
  return;
}
int main(){
int n;
sc(n);
//input the weights of the nodes
f(i,n) sc(a[i]);
//clear  the adjacency list
f(i,n+3) g[i].clear();
//input the n-1 edges 
int u,v;
//inputting the edges as the input taken from the 
//problem
f(i,n-1){
  sc(u);sc(v);
  g[u].pb(v);
  g[v].pb(u);
}
int root=1;
//set the timer from dfs numbering
kw = root; //set  1 if 1 based or 0 if based nodes  
dfs(root,-1);
f1(i,1,n+1) {pf(w[i]);sp;} br;
f1(i,1,n+1) {pf(pos[i]);sp;} br;
f1(i,1,n+1) {pf(to[i]);sp;} br;
return 0;
}
