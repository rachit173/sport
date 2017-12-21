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
ll memo[3333333];
ll cf[3333333];
ll memo1[3333333];
int dig(int n){
    int ret=0;
    while(n>0){
        if((n%10)%2==0)
        ret+=n%10;
        else
        ret-=n%10;
        n=n/10;
    }
    return abs(ret);
}
ll dp(int N){
    if(memo1[N]!=-1) return memo1[N];
    // cout<<N<<" "<<memo[2*N]<<" "<<cf[2*N-1]<<" "<<cf[N]<<endl;
    memo1[N]=dp(N-1) + memo[2*N] + 2*(cf[2*N-1]-cf[N]);
    return memo1[N];
}
int main(){
    int T;
    cin>>T;
    int N;
    RESET(memo1,-1);
    //preprocessing
    cf[0] = memo[0];
    for(int i=0;i<2222222;i++){
        memo[i] = dig(i);
    }
        for(int i=1;i<2222222;i++){
        cf[i] = cf[i-1] + memo[i];
    }
    memo1[0]=0;
    // f(i,100) cout<<memo[i]<<" ";
    // cout<<endl;
    while(T--){
        sc(N);
        // 
        ll ans=0;
        f1(i,1,N+1){
            f1(j,1,N+1) ans+=memo[i+j];
        }
        cout<<ans<<endl;
    }
return 0;
}
