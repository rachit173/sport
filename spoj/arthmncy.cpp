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
#define mod 10007
#define mod1 1000000009
#define oo 1000000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define N 10000007
int a[10000007];
int b[10000007];
ll bin(ll a,ll n){
    ll t=2;
    ll ret=1;
    while(n>0){
        if(n%2==1) ret=(ret*t)%mod;
        n=n>>1;
        t=(t*t)%mod;
    }
    return ret;
}
int main(){
RESET(a,1);
a[0]=0;
a[1]=0;
for(int i=2;i<N;i++){
    if(a[i]==0) continue;
    a[i]=1;
    for(int j=2*i;j<N;j+=i) a[j]=0; 
}
b[0]=a[0];
f1(i,1,N) b[i]=b[i-1]+a[i];
int n;
while(sc(n)==1){
    if(n==1) pf(0);
    else if(n==2) pf(1);
    else{
        ll p;
       // cout<<n;
        while(a[n]==0) n--;
        p=b[n];
        //cout<<p<<" "<<n<<endl;
        pf1(bin(2,p-1));
    }
    br;
}
return 0;
}
