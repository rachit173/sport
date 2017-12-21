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
int a[600000];
ll memo[600000];
int p[600000];
vi AL[600000];
int n,k;
multiset<int> ms;
// ll dp(int i){
//     if(i>n) return 0;
//     if(i==n) return 1;
//     if(i==n-1){
//         memo[n-1] = 1;
//         return 1;
//     }
//     // if(i==p[i]) return 0;
//     if(memo[i]!=-1) return memo[i];
//     int j = p[i];
//     ll ret = (2*dp(i+1))%mod;
//     // if(p[i]!=p[i+1]){
//     if(j<=n-1) ret = (ret-dp(j+1)+mod)%mod;
//     else if(j==n-1) ret = (ret - 1 +mod)%mod;
//     // }
//     memo[i] = ret;
//     return memo[i];
// }
ll dp(int x){
    // if(x<0) return 0;
    if(x==0){
        memo[x] =1;
        return memo[x];
    }
    if(x==-1) return 1;
    if(x<0) return 0;
    if(memo[x]!=-1) return memo[x];
    ll ret = (2*dp(x-1))%mod;
    f(i,AL[x].size()){
        ret = (ret-dp(AL[x][i]-1)+mod)%mod;
    }
    memo[x] = ret%mod;
    return memo[x];
}
int main(){
    cin>>n>>k;
    f(i,n) sc(a[i]);
    if(k==0){
        f(i,n) {
            if(a[i]==0){
                cout<<"0"<<endl;
                return 0;
            }
        }
    }
    ms.clear();
    set<int> s;
    f(i,n) p[i] = n;
    int j=0;
    if(a[0]<=k){
    ms.insert(a[0]);
    s.insert(a[0]);
    }
    f(i,n){
    
    if(s.size()<k+1)    { 
        for(j = j+1;j<n;j++){
            if(a[j]<=k){
                ms.insert(a[j]);
                s.insert(a[j]);
            }
            if(s.size()==k+1) break;
        }
    }
        if(j==n) break;
        p[i] = j;
        if(a[i]<=k){
            // cout<<a[i]<<" "<<ms.count(a[i])<<endl;
            ms.erase(ms.find(a[i]));
            if(ms.count(a[i])==0) s.erase(a[i]);
        }
    }
    f(i,n){
        AL[p[i]].pb(i);
    }
    // f(i,n) cout<<AL[i].size()<<" ";
    // cout<<endl;
    RESET(memo,-1);
    // f(i,n) cout<<p[i]<<" ";
    // cout<<endl;
    pf1(dp(n-1));br;
return 0;
}
