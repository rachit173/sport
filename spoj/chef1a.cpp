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
    #define oo 1000000000
    typedef vector<ll> vl;
    typedef pair<ll,ll> pll;
    typedef vector<pll> vll;
    typedef vector<int> vi;
    typedef pair<int,int> ii;
    typedef vector<ii> vii;
    int n;
    int a[6000];
    ll memo[201][501][501];
    ll dp(int st,int next,int curr){
      if(memo[st][next][curr]!=-1) return memo[st][next][curr];
      int s=min(next,curr);
      if(st>=199) {
        memo[st][next][curr]=1;
        return 1;
      }
      memo[st][next][curr]=0;
      //memo[st][next][curr]=(dp(st+1,a[st+2],next)+dp(st+1,a[st+2]+1,next-1))%mod;
      for(int i=0;i<=s;i++)
      memo[st][next][curr]=(memo[st][next][curr]+dp(st+1,a[st+2]+i,next-i))%mod;
      memo[st][next][curr]%=mod;
      return memo[st][next][curr];
    }
    int main(){
    int T;
    cin>>T;
    while(T--){
      sc(n);
      RESET(a,0);
      RESET(memo,-1);
      f(i,n) sc(a[i]);
      pf1(dp(0,a[1],a[0]));br;
    }
    return 0;
    } 