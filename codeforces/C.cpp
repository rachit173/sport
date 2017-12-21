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
vi AdjList[100005];
ll h[100005];
bool leaf[100005];
void dfs(int parent,int root,int height){
    h[root]=height;
    for(int i=0;i<AdjList[root].size();i++){
        if(AdjList[root][i]==parent) continue;
        if(h[AdjList[root][i]]==-1){
            dfs(root,AdjList[root][i],height+1);
        }
    }
    if(AdjList[root].size()==1&&AdjList[root][0]==parent) leaf[root]=true;
}
int main(){
    int n;
    sc(n);
    long double sum=0;
    RESET(h,-1);
    memset(leaf,0,sizeof(leaf));
    f(i,n+2) AdjList[i].clear();
    int u,v;
    if(n==1) {printf("%.15Lf\n",sum);return 0;}
    for(int i=0;i<n-1;i++){
        sc(u);
        sc(v);
        AdjList[u].pb(v);
        AdjList[v].pb(u);
    }
    dfs(1,1,0);
    long double d=0;
    for(int i=1;i<=n;i++){
        if(leaf[i]==true){ sum+=h[i];d+=1;}
    }
    long double ans=(sum)/d;
    printf("%.15Lf\n",ans);
return 0;
}
