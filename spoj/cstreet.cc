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
class UF {
  int *id,cnt,*sz;
  public:
    UF(int N) {
      cnt = N;
      id = new int[N];
      sz = new int[N];
      for(int i=0;i<N;i++) {
        id[i] = i; 
        sz[i] = 1;
      }
      }
      ~UF() {
          delete [] sz;
          delete [] id;
      }
      int find(int p){
        int root = p;
        while(root != id[root])
          root = id[root];
        while(p != root) {
          int newp = id[p];
          id[p] = root;
          p = newp;
        }
        return root;
      }
      void merge(int x,int y){
        int i = find(x);
        int j = find(y);
        if (i==j) return ;
        if(sz[i] < sz[j]) {
          id[i] = j;
          sz[j]+=sz[i];
        } else {
          id[j] = i;
          sz[i]+=sz[j];
        }
        cnt--;
      }
      //Are x and y in the same set
      bool connected(int x,int y){
        return find(x)==find(y);

      }
      int count(){
        return cnt;
      }
};
int main(){
  int T;
  cin>>T;
  while(T--){
     int p,n,m;
     
     cin>>p>>n>>m;
     UF ds(n+1);
     vii e(m+1);
     vii AL(m);
     int ans=0;
     int u,v,w;
    //  cout<<m<<endl;
     f(i,m){
      sc(u);sc(v);sc(w);
        e[i] = ii(u,v);
        AL[i] = ii(w,i);
     }
     sort(AL.begin(),AL.end());
    //  return 0;
     for(int i=0;i<m;i++)
     {
        int tmp = AL[i].ss;
        u = e[tmp].ff;
        v = e[tmp].ss;
        if(!ds.connected(u,v)){
          ans+=AL[i].ff;
          ds.merge(u,v);
        }
     }
     cout<<ans*p<<endl;
  }
return 0;
}
