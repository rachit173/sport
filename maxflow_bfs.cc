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
ll graph[5005][5005];
int n,m;
vi path;
queue<int,vector<int> > q;
bool bfs(int root,bool a[]){
    
}
int main(){
    cin>>n>>m;
    int u,v,c;
    RESET(graph,0);
    for(int i=0;i<m;i++){
        sc(u);sc(v);sc(c);
        graph[u][v]+=(ll)c;
        graph[u][v]+=(ll)c;        
    }
    ll maxflow = 0;
    ll tmp;
    bool a[n+1];
    f(i,n+1) a[i]=false;
    while(1){
        path.clear();
        f(i,n+1) a[i]=false;
        if(dfs(1,a))
        {
            path.pb(1);
            ll mn=oo;
            fr(i,path.size()-1) mn=min(graph[path[i+1]][path[i]],mn);
            fr(i,path.size()-1){
                //cout<<path[i+1]<<" "<<path[i]<<endl;
                //a[path[i+1]]=a[path[i]]=false;
                graph[path[i+1]][path[i]] -=mn;
                graph[path[i]][path[i+1]] +=mn;
            }
            //cout<<mn<<" ";
            if(mn<=0) break;
            maxflow+=mn;          
        }
        else break;
    }
    pf1(maxflow);br;
return 0;
}
