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
int n,x,k;
cin>>n>>x>>k;
vi a(n);
f(i,n) sc(a[i]);
sort(a.begin(),a.end());
vi b(n);
ll ans=0;
f(i,n) b[i] = a[i]/x;
int j=0;
f(i,n){
    int s = k+(a[i]-1)/x ;
    pair<vi::iterator,vi::iterator> bounds= equal_range(b.begin(),b.end(),s);
    
    // if((bounds.first-b.begin())>=i) tmp-=(bounds.first-b.begin());
    // else tmp-=i;
    j = bounds.first-b.begin();
    if(a[j]<a[i]){
        vi::iterator it1 = lower_bound(a.begin(),a.end(),a[i]);
        j = it1-a.begin();
    }
    ll tmp = (bounds.second-b.begin())-j;
    if(tmp>0&&*bounds.ff==s) ans+=tmp;
}
cout<<ans<<endl;
return 0;
}
