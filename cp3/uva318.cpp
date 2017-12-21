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
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define oo 1000000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int G[502][502];
int start[502];
vii edges(25000);
int n,m;
void dfs(int foo){
  //if(start[foo]!=-1) return ;
  int s=start[foo];
  //cout<<s<<endl;
  for(int i=1;i<=n;i++){
    if(i!=foo&&(s+G[foo][i])<start[i]){
    start[i]=s+G[foo][i];
    dfs(i);
    }
  }

}
int main(){
  int k=0;
while(1){
  k++;
  cin>>n>>m;
  if(n==0&&m==0) break;
  //f(i,502) AdjList[i].clear();
  f2(i,j,n+1,n+1) G[i][j]=oo;
  f(i,n+1) start[i]=oo;
  //RESET(visit,0);
  int u,v,ti;
  f(i,m){
    sc(u);sc(v);sc(ti);
    G[u][v]=G[v][u]=ti;
    edges[i]=ii(u,v);
  }
  //f2(i,j,n,n) cout<<G[i+1][j+1]<<" ";
  start[1]=0;
  dfs(1);
  //for(int i=1;i<=n;i++) {pf(start[i]);sp;}
  //br;
  double tu,tv,l,mn,mx,tmp;
  int key,t;
  ii pkey;
  double ans=0;
  int opt1=0;
  f(i,m){
    u=edges[i].ff;
    v=edges[i].ss;
    tu=start[u];
    tv=start[v];
    l=G[u][v];
    mx=max(tu,tv);
    mn=min(tu,tv);
    if(tu>tv) t=u;
    else t=v;
    //cout<<tu<<" "<<tv<<" "<<G[u][v]<<endl;
    if(mx>ans){ans=mx;opt1=1;key=t;}
    if((mx-mn)<l){ 
      tmp=(mx+(l-(mx-mn))/2.0);
      if(tmp>ans){
        ans=tmp;
        opt1=2;
        pkey=edges[i];
      }
    }
  }
  u=min(pkey.ff,pkey.ss);
  v=max(pkey.ff,pkey.ss);
  printf("System #%d\n",k);
  if(opt1==1)
  printf("The last domino falls after %.1lf seconds, at key domino %d.\n",ans,key);
  else
  printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n",ans,u,v);
br;
}
return 0;
}
