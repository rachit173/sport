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
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define pb push_back
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
bool same(vi& a,vi& b){
  if(a.size()!=b.size()) return false;
  for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return false;
  return true;
}
int n,m;
inline bool isb(vi &a){
  if(a.size()==n) return true;
  return false;
}
int main(){
cin>>n>>m;
vi lst[n+1];
for(int i=1;i<=n;i++) lst[i].pb(i);
int u,v;
for(int i=1;i<=m;i++){
  sc(u);sc(v);
  lst[u].pb(v);lst[v].pb(u);
}
for(int i=1;i<=n;i++) sort(lst[i].begin(),lst[i].end());
vector<vi> a;
int type[n+1];
RESET(type,-1);
a.pb(lst[1]);
type[1]=0;
for(int i=2;i<=n&&a.size()<=3;i++){
 int sz=a.size(); 
  for(int j=0;j<sz;j++){
    if(same(a[j],lst[i])) {type[i]=j;break;}
  }
  if(type[i]==-1){a.pb(lst[i]);type[i]=sz;}
}
//cout<<a.size()<<endl;
if(a.size()>3) cout<<"No\n";
else {
  int opt=-1;
  for(int i=0;i<a.size();i++){
    if(isb(a[i])){opt=i;break;}
  }
  if(a.size()==1){
    if(opt==-1) cout<<"No\n";
    else{
      cout<<"Yes\n";
      for(int i=1;i<=n;i++) printf("a");
      br;
    }
  }
  else if(a.size()==2){
    if(opt==-1){
      cout<<"Yes\n";
      for(int i=1;i<=n;i++) type[i]==0?printf("a"):printf("c");
      printf("\n");
    }
    else{
      cout<<"Yes\n";
      for(int i=1;i<=n;i++) type[i]==opt?printf("b"):printf("a");
      printf("\n");
    }
  }
  else{
    if(opt==-1) cout<<"No\n";
    else{
      cout<<"Yes\n";
      int x=(opt+1)%3;
      int y=(opt+2)%3;
      for(int i=1;i<=n;i++){
        if(type[i]==opt) printf("b");
        else if(type[i]==x) printf("a");
        else printf("c");
      }
      br;
    }
  }
}
return 0;
}
