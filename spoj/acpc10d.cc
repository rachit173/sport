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
int memo[100001][3];
int a[100001][3];
int n;
int dp(int foo,int col){
    if(memo[foo][col]!=-1) return memo[foo][col];
    if(col==1){
        memo[foo][col] = a[foo][col]+min(min(dp(foo,2),dp(foo+1,2)),min(dp(foo+1,1),dp(foo+1,0)));
        return memo[foo][col];
    }
    else if(col==0){
        memo[foo][col] = a[foo][col]+min(min(dp(foo,1),dp(foo+1,col)),dp(foo+1,1));
        return memo[foo][col];
    }
    else{
        memo[foo][col] = a[foo][col]+min(dp(foo+1,2),dp(foo+1,1));
        return memo[foo][col];
    }
}
int main(){
    int t_i=0;
    while(1){
        sc(n);
        if(n==0) break;
        RESET(memo,-1);
        f(i,n)
            f(j,3) sc(a[i][j]);
        //preprocess targets
        memo[n-2][2] = a[n-2][2]+a[n-1][1];
        memo[n-2][1] = min(a[n-2][1]+a[n-1][0]+a[n-1][1],min(a[n-2][1]+a[n-1][1],a[n-2][1]+memo[n-2][2]));
        memo[n-2][0] = min(a[n-2][0]+memo[n-2][1],min(a[n-2][0]+a[n-1][1],a[n-2][0]+a[n-1][0]+a[n-1][1]));
        // f(i,3) pf(memo[n-2][i]);
        int ans = dp(0,1);
        printf("%d. %d\n",t_i+1,ans);
        t_i++;
    }
return 0;
}
