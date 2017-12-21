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
vi AL[123456];  //Adjacency List
int visit[123456];
int color[123456];
int st[123456];
int ft[123456];
int n,m;
int TIME=0;
void input_graph(){
  sc(n);sc(m);
  int u,v;
  for(int i=0;i<n;i++){
    sc(u);sc(v);
    AL[u].pb(v); AL[v].pb(u);  
  }
}
bool dfs_color(int root,int c){
  if(color[root]!=-1){
    if(color[root]==c) return true;
    else return false;
  }
  color[root]=c;
  c = c^1;
  for(int i=0;i<(int)AL[root].size();i++){
    if(!dfs_color(AL[root][i],c)) return false;
  }
  return true;
}
bool color_graph(){
  RESET(color,-1);
  // taking the nodes to be zero indexed
  bool ret = true;
  for(int i=0;i<n;i++){
     if(color[i]==-1) 
       ret = ret&dfs_color(i,0);
     if(!ret) return ret;
    }
  return ret;
}
void dfs_convert_tree_to_array(int v){
  st[v] = TIME++;
  visit[v]=1;
  for(int i=0;i<(int)AL[v].size();i++){
    if(!visit[AL[v][i]]) dfs_convert_tree_to_array(AL[v][i]);
  }
  ft[v] = TIME;

}
void tree_to_array(){
  TIME = 0;
  RESET(visit,0);
  dfs_convert_tree_to_array(0);
}
int main(){
  input_graph();    //take input a graph with no weighted edges
  bool is_it_2color = color_graph();
  tree_to_array();
return 0;
}
