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
map<ii,bool> graph;
vi AdjList[100005];
int n,m;
int n1,n2;
vi path;
bool dfs(int root,bool a[]){
   // cout<<"root : "<<root<<endl;
    if(root == n+1){
        return true;
    }
    if(a[root]==true) return false;
    a[root]=true;
   // cout<<"here";
    for(int i=0;i<AdjList[root].size();i++){
     //   cout<<AdjList[root][i]<<" "<<graph[ii(root,AdjList[root][i])]<<",";
        if(graph[ii(root,AdjList[root][i])]==true){
            ////cout<<i<<" ";
            if(dfs(AdjList[root][i],a)==true) { 
                //path.pb(AdjList[root][i]);
                graph[ii(root,AdjList[root][i])]=false; 
                graph[ii(root,AdjList[i][root])]=true;
                a[AdjList[root][i]]=false;
                return true; 
            }
        }
    }
    a[root]=false;
    return false;
}
int main(){
    cin>>n1>>n2>>m;
    int u,v,c;
    n=n1+n2;
    //RESET(graph,false);
    for(int i=0;i<m;i++){
        sc(u);sc(v);
        AdjList[u].pb(n1+v);
        AdjList[n1+v].pb(u);
        graph[ii(u,n1+v)]=true;        
    }
    for(int i=1;i<=n1;i++) {
        AdjList[0].pb(i);
        AdjList[i].pb(0);
        graph[ii(0,i)]=true;
    }
    for(int i=1;i<=n2;i++) {
        AdjList[i+n1].pb(n+1);
        AdjList[n+1].pb(i+n1);
        graph[ii(i+n1,n+1)]=true;
    }
    ll maxflow = 0;
    ll tmp;
    bool a[n+2];
    f(i,n+2) a[i]=false;
    while(1){
        // path.clear();
        a[0]=false;
        if(dfs(0,a))
        {
            // path.pb(0);
            // //ll mn=oo;
            // //fr(i,path.size()-1) mn=min(graph[path[i+1]][path[i]],mn);
            // fr(i,path.size()-1){
            //     //cout<<path[i+1]<<" "<<path[i]<<endl;
            //     graph[ii(path[i+1],path[i])] = false;
            //     graph[ii(path[i],path[i+1])] =true;
            // }
            //cout<<mn<<" ";
            maxflow++;          
        }
        else break;
    }
    pf1(maxflow);br;
return 0;
}
