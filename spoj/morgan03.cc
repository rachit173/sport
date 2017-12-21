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
int T;
cin>>T;
while(T--){
    int n;
    cin>>n;
    ll a[n];
    f(i,n) sc1(a[i]);
    sort(a,a+n);
    ll ans = 0;
    ans+=3*(a[0]+a[n-1]);
    for(int i=1;i<n-1;i++)
    ans+=2*a[i];
    ll p=ans,q=6;
    if(p%3==0){
        p/=3;
        q/=3;
    }
        if(p%2==0){
        p/=2;
        q/=2;
    }
    if(q==1) cout<<p<<endl;
    else cout<<p<<"/"<<q<<endl;
}
return 0;
}
