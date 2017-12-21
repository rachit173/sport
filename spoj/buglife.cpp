//created by Rachit Tibrewal
//This problem checks whether a graph is bipartite 
//Or in other words is it a two color graph
//Also this code allows the graph to be disconnected
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
#define ff first
#define ss second
#define pb push_back
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
int  n,k;
vi AdjList[2005];
int a[10000];
bool dfs(int jk,int color){
    //cout<<jk<<" "<<a[jk]<<" "<<color<<endl;
    if(a[jk]!=0){ 
        if(a[jk]!=color) return true;
        return false;
    }
    a[jk]=color;
    color=1+(color)%2;
    for(int i=0;i<(int)AdjList[jk].size();i++)
        if(dfs(AdjList[jk][i],color)) return true;
    return false;
}
int main(){
int T;
int t=0;
cin>>T;
while(T--){
    t++;
    sc(n);sc(k);
    RESET(a,0);
    f(i,2005) AdjList[i].clear();
    int u,v;
    f(i,k){
        sc(u);sc(v);
        AdjList[u].pb(v);
        AdjList[v].pb(u);
    }
    bool ans=false;
    for(int i=1;i<=n;i++){
    if(a[i]==0) ans=ans|dfs(i,1);
    }
   // f1(i,1,n+1) {pf(a[i]);sp;}
    //br;
    printf("Scenario #%d:\n",t);
    if(ans)
    printf("Suspicious bugs found!\n");
    else
    printf("No suspicious bugs found!\n");
}
return 0;
}
