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
int dig(int n){
    int ret=0;
    while(n>0){
        ret++;
        n=n/10;
    }    
    return ret;
}
bool ispal(int n){
    int p=0;
    int tmp=n;
    while(tmp>0){
        p=p*10+tmp%10;
        tmp=tmp/10;
    }
    return p==n;
}
int main(){
    ll ans=0;
int k,p;
cin>>k>>p;
int ct=0;
int i=1;
int p1=0;
int b=10;
int flag4=0;
set<ll> s;
int d;
// for(int i=1;i<100001;i++){
//     if(ispal(i)){
//         cout<<i<<endl;
//         d = dig(i);
//         if(d%2==0){
//             s.insert(i);
//             s.insert(i*100);
//             s.insert(i*10000);
//         }
//         else{
//             s.insert(i*10);
//             s.insert(i*1000);
//             if(d<=4) s.insert((i*100000));
//         }
//     }
// }
i=1;
while(ct<100001){
        int tmp=i;
        int x=1;
        p1=0;
        while(tmp>0){
            p1=p1*10+tmp%10;
            x=x*10;
            tmp=tmp/10;
        }
        for(int j=0;j<10;j++){
            
        }
        // cout<<(p1+(ll)i*x)<<endl;
        s.insert((p1+(ll)i*x));
        ct++;
    i++;
}
ct=0;
for(auto e:s){
    // cout<<e<<endl;
    ans = (ans+e)%p;
    ct++;
    if(ct>=k) break;
}
cout<<ans<<endl;
return 0;
}
