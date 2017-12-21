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
int main(){
    int n;
    cin>>n;
    int a[n][4];
    f(i,n){
        sc(a[i][0]);
        sc(a[i][1]);
        sc(a[i][2]);
        sc(a[i][3]);
    }
    vi arr1;
    vi arr2;
    f(i,n){
        f(j,n) arr1.pb(a[i][0]+a[j][1]);
    }
    f(i,n){
        f(j,n) arr2.pb(a[i][2]+a[j][3]);
    }
    ll ans=0;
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    f(i,arr1.size()){
        pair<vi::iterator,vi::iterator> bounds = equal_range(arr2.begin(),arr2.end(),-arr1[i]);
        ans+=(bounds.ss-bounds.ff);
    }
    cout<<ans<<endl;
return 0;
}
