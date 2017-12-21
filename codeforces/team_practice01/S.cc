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
typedef struct wave{
    ll m;
    ll f;
    ll w;
}wave;
bool visit[1000006];
bool cmp(wave &x,wave &y){
    return x.m<y.m;
}
bool cmp1(const ll &val,const wave &x){
    return val<=x.m;
}
// inline bool operator<(const wave& x,const int&val)
// {
//     return val<x.m;
// }
ll memo[1000006];
ll memo1[1000006];
int main(){
    int n;
    cin>>n;
    wave a[n];
    f(i,n){
        sc1(a[i].m);
        sc1(a[i].f);
        sc1(a[i].w);
    }
    sort(a,a+n,cmp);
    ll ans=0;
    // return 0;
    memo1[n]=0;
   RESET(visit,0);
    for(int i=n-1;i>=0;i--){
            ll tmp;
            ll val = a[i].m + a[i].w;
            int index = (int)(upper_bound(a,a+n,val,cmp1)-&a[0]);
            // cout<<i<<" "<<index;
            if(index<n)
            tmp = a[i].f+memo1[index];
            else tmp = a[i].f;
            memo[i] = tmp;
            // cout<<memo[i];
            memo1[i] = max(memo1[i+1],memo[i]); 
            ans = max(tmp,ans);
    }
    ans =memo1[0];
    f1(i,1,n) ans = max(ans,memo1[i]);
    cout<<ans;
return 0;
}
