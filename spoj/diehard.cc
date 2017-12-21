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
ll memo[1005][1005][3];
ll dp(int h,int a,int p) {
    // cout<<h<<" "<<a<<" "<<p<<endl; 
    if(h<0||a<0) return -1;
    if(memo[h][a][p]!=-1) return memo[h][a][p];
    ll ret = 0;
        if(p==0){
            ret = max(ret,1+dp(h+3,a+2,1));
            if(h>5&&a>10) ret = max(ret,1+dp(h-5,a-10,2));
        }
        else if(p==1){
            if(h>20) ret = max(ret,1+dp(h-20,a+5,2));
            if(h>5&&a>10) ret = max(ret,1+dp(h-5,a-10,2));
        }
        else {
            ret = max(ret,1+dp(h+3,a+2,1));
            if(h>20) ret = max(ret,1+dp(h-20,a+5,0));
        }
    memo[h][a][p] = ret;
    return memo[h][a][p];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int h,a;
        RESET(memo,-1);
        sc(h);
        sc(a);
        cout<<max(dp(h,a,0),max(dp(h,a,1),dp(h,a,2)))<<endl;
    }
return 0;
}
