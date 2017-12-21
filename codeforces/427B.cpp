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
#define pb push_back
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
int n,k;
cin>>k>>n;
vi a;
int tmp=n;
int sum=0;
while(tmp>0){sum+=(tmp%10);a.pb(tmp%10); tmp/=10;}
if(sum>=k) cout<<"0\n";
else{
  int t=k-sum;
  int ans=0;
  sort(a.begin(),a.end());
  //f(i,a.size()) {pf(a[i]);sp;}
  f(i,a.size()){
    if(t<=0) break;
    t=t-(9-a[i]);
    ans++;
  }
  if(t<=0) cout<<ans<<endl;
}
return 0;
}
