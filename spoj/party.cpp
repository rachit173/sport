#include<bits/stdc++.h>
using namespace std;
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
int w,n;
int ans2;
int knapSack(ii a[]){
  int K[n+1][w+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){
    if(i==0||j==0) K[i][j]=0;
    else if(a[i-1].ff<=j)
        K[i][j]=max(a[i-1].ss+K[i-1][j-a[i-1].ff],K[i-1][j]);
      else K[i][j]=K[i-1][j];
    }
  }
  ans2=w;
  for(int i=w-1;i>=0;i--)
  if(K[n][i]==K[n][w]) ans2=i;
  return K[n][w];
}
int main(){
while(1){
  sc(w);sc(n);
  if(w==0&&n==0) break;
  ii a[n];
  for(int i=0;i<n;i++) {sc(a[i].first);sc(a[i].second);}
  int ans=knapSack(a);
  cout<<ans2<<" "<<ans<<endl;
}
return 0;
}
