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
int N,M,S;
//int visit[20005];
//int vis[20005];
int memo[20005][10005];
vii AdjList[20005];
ii tmp;
int dfs(int u,int v){
    if(u>v){
        int t=u;
        u=v;
        v=u;
    }
    if(memo[u][v]!=-1) return memo[u][v];
    if(u==v) return oo;
    memo[u][v]=0;
    for(int i=0;i<AdjList[u].size();i++){
        tmp=AdjList[u][i];
        memo[u][v]=max(memo[u][v],min(tmp.ff,dfs(tmp.ss,v)));
    }
    return memo[u][v];
}
int main(){
    RESET(memo,-1);
    //RESET(visit,0);
    cin>>N>>M>>S;
    int u,w,v;
    for(int i=0;i<M;i++){
        sc(u);sc(v);sc(w);
        AdjList[u].pb(ii(w,v));
        AdjList[v].pb(ii(w,u));
    }
    f(i,N) sort(AdjList[i+1].rbegin(),AdjList[i+1].rend());
    //return 0;
    f(i,S){
        sc(u);sc(v);
        pf(dfs(u,v));br;
    }
return 0;
}
