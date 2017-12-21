#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define br printf("\n");
#define sc(a) scanf("%d",&a);
#define sc2(a) scanf("%lld",&a);
#define sc3(a) scanf("%llf",&a);
#define pf(a) printf("%d",a);
#define pf2(a) printf("%lld",a);
#define ll long long int
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))

typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n,m;
char grid[200][200];
int main(){
int T;
cin>>T;
while(T--){
  cin>>n>>m;
  f(i,n) cin>>grid[i];
  vii a;
  f(i,n)f(j,m) if(grid[i][j]=='1')a.pb(ii(i,j));
  f(i,n){
    f(j,m){
    if(grid[i][j]=='0'){
      int mn=1000;
      f(k,a.size()){
        mn=min(mn,abs(i-a[k].ff)+abs(j-a[k].ss));
      }
      pf(mn);printf(" ");
    }
    else printf("0 ");
    }
    br;
  }
}
return 0;
}
