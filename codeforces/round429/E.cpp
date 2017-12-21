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
ll memo[1000000][300];
int main(){
    int n;
    cin>>n;
    ll a[n];
    f(i,n) cin>>a[i];
    vector<vi > vec(1);
    vec[0].pb(a[0]);
    ll t,t1;
    set<ll > ::iterator it;
    for(int i=1;i<300;i++){
        for(int j=0;j<vec.size();j++){
            t=vec[j][0];
            t1=sqrt(t*a[i]);
            if(t1*t1==t*a[i]){
                vec[j].pb(a[i]);
                break;
            } 
        }
    }
    int m=vec.size();

return 0;
}
