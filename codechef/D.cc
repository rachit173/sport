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
int a[100005];
int b[100005];
bool notprime(int x){
    for(int i=2;i<=x/2;i++) if(x%i==0) return true;
    return false;
}
int arr[100005];
int n;
// void make2(){
//     arr[0]=1;
//     f1(i,1,100004) arr[i] = (arr[i-1]*2)%mod; 
// }
ll binexp(ll p,ll pow1){
    // cout<<"power "<<pow1<<" "<<p<<endl;
    ll ret = 1;
    ll tmp=p%mod;
    while(pow1>0){
        if(pow1%2) ret = (ret*tmp)%mod;
        tmp=(tmp*tmp)%mod;
        pow1 = pow1>>(ll)1;
    }
    // cout<<ret<<endl;
    return ret%mod;    
}
ll quarticexp(ll p,ll l){
    ll ret = p;
    while(l--){
        ret = (ret*ret)%mod;
    }
    return ret%mod;
}
int main(){
    // RESET(arr,0);
    // make2();
int T;
cin>>T;
int t;
ll ans = 1;
// pf(1);
while(T--){
    ans=1;
    sc(n);
    f(i,n) sc(a[i]);
    for(int z=2;z<407;z++){
        // pf(10);
        if(notprime(z))continue;
        // f(i,n) a[i]=arr[i];
        RESET(b,0);
        f(j,n){
            t=0;
            while(a[j]%z==0){
                a[j]= a[j]/z;
                t++;
            }
            b[j] = t;
        }
        // if(z>10) continue;
        sort(b,b+n);
        // f(i,n) pf(b[i]); 
        // br;
        ll t1 = 1;
        ll p = z;
        ll t2 = 0;
        ll t3;
        ll l;
        // ll ppow[100100];
        ll ppow2[100005];
        ppow2[0] =p;
        // f1(i,1,100100){ ppow[i] = (ppow[i-1]*p)%mod}
        f1(i,1,100005) {ppow2[i] = (ppow2[i-1]*ppow2[i-1])%mod;}
        f(i,n){
            if(b[i]==0) continue;
            l = n-i;
            t1 = b[i];  
            t2 = binexp(ppow2[l-1],t1)%mod;
            // if(l==0) t2 = binexp(p,b[i])%mod;
            // cout<<l<<" "<<p<<" "<<b[i]<<" "<<t3<<endl;
            // cout<<t2;
            ans = (ans*t2)%mod;
        }
    }
    // pf1(ans);br;
    int memo[100005];
    RESET(memo,0);
    f(i,n) memo[a[i]]++;
    for(int i=400;i<100005;i++){
        if(memo[i]>0){
            // pf(i);
            ans=ans%mod;
            ll tmp = (binexp(i,mod-2)*quarticexp(i,memo[i]))%mod;
            ans = (ans*tmp)%mod;
        }
    }
    cout<<ans<<endl;
}
return 0;
}
