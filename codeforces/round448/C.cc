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
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define mod 1000000007
#define mod1 1000000009
#define oo 1000000000
const double PI = acos(-1);
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll memo[2][1<<19];
int a[100005];
int main(){
int n;
cin>>n;
int primes[19] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
RESET(memo,0);
f(i,n) sc(a[i]);
int cnt[71]={0};
f(i,n) cnt[a[i]]++;
int mask[71]={0};
for(int i=2;i<71;i++){
    int tmp = i;
   for(int j=0;j<19;j++){
       int c=0;
       while(tmp%primes[j]==0){
        c++;
        tmp/=primes[j];
       } 
        mask[i] = mask[i]^((c%2)<<j);
   } 
}
ll ex[100005];
ex[0] = 1;
for(int i=1;i<100005;i++){
    ex[i] = (ex[i-1]*2)%mod;
}
memo[0][0]=1;
ll f1,f0;
for(int i=1;i<=70;i++){
    if(cnt[i]==0){
        f0 = 1;
        f1 = 0;
    } 
    else {
        f1 = ex[cnt[i]-1]%mod;
        f0 = ex[cnt[i]-1]%mod;
    }
   for(int j=0;j<(1<<19);j++){
        memo[1][j^mask[i]] = (memo[1][j^mask[i]] + memo[0][j] *f1)%mod;
        memo[1][j] = (memo[1][j]+memo[0][j]*f0)%mod;
    }
    for(int j=0;j<(1<<19);j++){
        memo[0][j] = memo[1][j];
        memo[1][j]=0;
    } 
}
cout<<memo[0][0]-1<<endl;
return 0;
}
