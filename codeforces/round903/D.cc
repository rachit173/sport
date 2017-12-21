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
// ll a[300000];
int main(){
int n;
cin>>n;
map<int,vi > mp;
vi a(n);
f(i,n){ 
    sc(a[i]);
    mp[(int)a[i]].pb(i);
}
ll ans=0;
ll cf[n+1];
cf[0] = a[0];
f1(i,1,n) cf[i] = cf[i-1]+a[i];
for(int i=1;i<n;i++){
    ll tmp=(ll)i*(ll)a[i]-cf[i-1];
    if(mp.find(a[i]+1)!=mp.end()){
        vi &arr = mp[a[i]+1];
        vector<int>::iterator e = upper_bound(arr.begin(),arr.end(),i);
        // e--;
        // cout<<*e<<" ";
        // cout<<(e-arr.begin())<<" "<<i<<" "<<a[i]+1<<endl;
        tmp+=(e-arr.begin());
    }
    if(mp.find(a[i]-1)!=mp.end()){
                vi &arr = mp[a[i]-1];
        vector<int>::iterator e = upper_bound(arr.begin(),arr.end(),i);
        // e--;
        // cout<<*e<<" ";
        // cout<<(e-arr.begin())<<" "<<i<<" "<<a[i]-1<<endl;
        tmp-=(e-arr.begin());
    }
    // cout<<"tmp"<<":"<<tmp<<endl;
    ans+=tmp;
}
cout<<ans<<endl;
return 0;
}
