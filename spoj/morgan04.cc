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
int n;
ll a[200005];
int l[200005];
int r[200005];
vector<vi> rt(200005);
vector<vi> lt(200005);
ll memo[200005];
int haha[200005];
ll dp(int pivot){
    if(pivot<0||pivot>n) return 0;
    if(memo[pivot]!=-1)  return memo[pivot];
    ll ret=0;
    int t = pivot-l[pivot]-1;
    while(t>=0&&t+r[t]+1>pivot) t--;
    memo[pivot]= max(a[pivot]+dp(t),dp(pivot-1));
    return memo[pivot];
    // else {
    //     memo[pivot][tp]= max(a[pivot]+dp(pivot+(r[pivot]+1),1),dp(pivot+1,1));
    // }
}
int main(){
RESET(memo,-1);
RESET(haha,-1);
cin>>n;
f(i,n) sc1(a[i]);
f(i,n) {sc(l[i]); lt[i-l[i]].pb(i);}
f(i,n) { sc(r[i]); }
// for(int i=n-1;i>=0;i++){

// } 
cout<<dp(n-1)<<endl;
return 0;
}
