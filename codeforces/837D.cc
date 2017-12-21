#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sc1(a) scanf("%lld",&a);
#define pf1(a) printf("%lld",a);
#define sc2(a) scanf("%d %d",&a.first,&a.second);
#define br printf("\n");
#define sp printf(" ");
#define ll long long int
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
int memo[202][202][2];
int memo1[202][202][2][2];
ii b[202];
int n,k;
int dp(int st,int k,int t){
    if(memo[st][k][t]!=-1) return memo[st][k][t];
    int ans=0;
    if(t==0){
    if(dp(st+1,k,0)>dp(st+1,k,1)){
        memo[st][k][t]=dp(st+1,k,0);
        memo1[st][k][0]=memo1[st+1][k][0];
        memo1[st][k][1]=memo1[st+1][k][1];
    }
    }
    else{
        int x[2],y[2];
        dp(st+1,k-1,0);dp(st+1,k-1,1);
        x[0]=memo1[st][k-1][0];
        x[1]=memo1[st][k-1][1];
                y[0]=memo[st][k-1][0];
        y[1]=memo[st][k-1][1];
    }
}
int main(){
    RESET(memo,-1);
cin>>n>>k;
ll a[n];
f(i,n) sc1(a[i]);
//int c[n]={0};
f(i,n) b[i]=ii(0,0);
int t;
for(int i=0;i<n;i++){
    t=a[i];
    while(t>0){
        t=t/2;
        b[i].ff++;
    }
}
for(int i=0;i<n;i++){
    t=a[i];
    while(t>0){
        t=t/5;
        b[i].ss++;
    }
}
ans=
cout<<ans<<endl;
return 0;
}
