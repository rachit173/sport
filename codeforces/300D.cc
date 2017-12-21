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
#define mod2 1000000007
#define mod1 1000000009
#define oo 1000000000
#define mod 7340033
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll check[100005]
ll fun(int n,int k){
    if(k == 0) return 1;
    if(n == 1) return 0;
    if(n%2==0) return 0;
    ll ret = 0;

}
int main(){
    int n,k;
    int q;
    cin>>q;
    while(q--){
        sc(n);sc(k);
        ll ans = fun(n,k);
        pf1(ans%mod);br;
    }    
return 0;
}
