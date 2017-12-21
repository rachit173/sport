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
using temp_t = std::tuple<long long, long long>;
ll memo[1000][1000];
long long calcInverse(long long a, long long n)
{
    long long t = 0, newt = 1;
    long long r = n, newr = a;  
    while (newr != 0) {
        auto quotient = r /newr;
        tie(t, newt) = make_tuple(newt, t- quotient * newt);
        tie(r, newr) = make_tuple(newr, r - quotient * newr);
    }
    if (r > 1)
        throw runtime_error("a is not invertible");
    if (t < 0)
        t += n;
    return t;
}
ll p,n,q;
// ll seg2[3000007];
ll a[1000007];
ll b[1000007];
//segment tree for range sum query 
ll binexp(ll p1,int pow1,ll cmod){
    // cout<<"power "<<pow1<<" "<<p<<endl;
    ll ret = 1;
    ll tmp=p1%cmod;
    while(pow1>0){
        if(pow1%2) ret = (ret*tmp)%cmod;
        tmp=(tmp*tmp)%cmod;
        pow1 = pow1>>1;
    }
    // cout<<ret<<endl;
    return ret%cmod;
}
// void update2(int index,int l,int r,ll val,int base){
//     if(r<=l){
//         seg2[base] =val%p;
//         return ;
//     }
//     int mid = l+(r-l+1)/2;
//     if(index<mid){
//         update2(index,l,mid-1,val,2*base);
//         seg2[base] = (seg2[2*base]*seg2[2*base+1])%p;
//     }else{
//         update2(index,mid,r,val,2*base+1);
//         seg2[base] = (seg2[2*base]*seg2[2*base+1])%p;
//     }
// }
// ll search2(int start,int end,int l,int r,int base){
//     if(r<=l){
//         return seg2[base];
//     }
//     int mid = l+(r-l+1)/2;
//     if(end<mid){
//         return search2(start,end,l,mid-1,2*base);
//     }
//     else if(start>=mid){
//         return search2(start,end,mid,r,2*base+1);
//     }
//     else if(start==l&&end==r) return seg2[base];
//     return (search2(start,mid-1,l,mid-1,2*base)*
//                 search2(mid,end,mid,r,2*base+1))%p;
// }
ll f[15][1000006];
ll cf[15][1000006];
ll exponents[15][50];
int main(){
int T;
cin>>T;
while(T--){
    sc1(n);
    sc1(p);
    vi factors;
    
    sc1(q);
    // f(i,3*n+2) seg2[i]=1;
    f(i,n+4){
        f(j,11) f[j][i]=cf[j][i]=0;
    }
    f(i,n){
        sc1(a[i]);
        // a[i]=a[i]%p;
        // update2(i,0,n-1,a[i],1);
    }
    ll tmp=p;
    ll phi=p;
    int t;
    int kw=-1;
    for(int i=2;i<=50000;i++){
        if(tmp%i==0){
            phi = (phi/i)*(i-1);
            while(tmp%i==0) tmp=tmp/i;
            factors.pb(i);
            kw++;
            for(int j=0;j<n;j++){
                t=0;
                while(a[j]%i==0){ a[j]=a[j]/i; t++;}
                f[kw][j]=t;
            }
            cf[kw][0]=f[kw][0];
            for(int j=1;j<n;j++) cf[kw][j] = f[kw][j]+cf[kw][j-1];
        }
    }
    if(tmp>1){
        factors.pb(tmp);
        phi = (phi/tmp)*(tmp-1);
        kw++;
        for(int j=0;j<n;j++){
                t=0;
                while(a[j]%tmp==0){ a[j]=a[j]/tmp; t++;}
                f[kw][j]=t;
        }
        cf[kw][0]=f[kw][0];
        for(int j=1;j<n;j++) cf[kw][j] = f[kw][j]+cf[kw][j-1];
    }
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    ll cpr[n+2];
    cpr[0]=a[0];
    ll inv[n+2];
    inv[0] = binexp(cpr[0],phi-1,p);
    for(int i=1;i<n;i++){
        cpr[i] = (cpr[i-1]*a[i])%p;
        inv[i] = binexp(cpr[i],phi-1,p);
    }
    // for(int i=0;i<n;i++) cout<<inv[i]<<" ";
    // cout<<endl;
    ll g;
    for(int i=0;i<factors.size();i++){
        g = factors[i];
        exponents[i][0]=1;
        for(int j=1;j<50;j++){
            exponents[i][j] = (exponents[i][j-1]*g)%p;
        }
    }
    ll x=0;
    int u,v,l,r;
    int m=(q/64)+2;
    for(int i=0;i<m;i++) sc1(b[i]);
    // for(int i=0;i<20;i++) {pf1(seg2[i]);sp;} br;
    for(int i=0;i<q;i++){
        if(i%64==0){
            u = (b[i/64]+x)%n;
            v = (b[(i/64)+1]+x)%n;
            l = min(u,v);
            r = max(u,v);
            // x = search2(l,r,0,n-1,1)%p;
            x=1;
            // cout<<l<<" "<<r<<endl;
            for(int j=0;j<factors.size();j++){
                // cout<<factors[j]<<endl;
                x = (x*(l==0?exponents[j][(cf[j][r])]:(exponents[j][(cf[j][r]-cf[j][l-1])])))%p;
            }
            if(l==0){
                x = (x*cpr[r])%p;
                // cout<<cpr[r]<<endl;
            }
            else{
                x = (x*cpr[r])%p;
                x = (x*inv[l-1])%p;
                // cout<<cpr[r]<<" "<<inv[l-1]<<endl;
            }
            // cout<<x<<endl;
            x = (x+1)%p;   
            
        }
        else {
            u = (l+x)%n;
            v = (r+x)%n;
            l = min(u,v);
            r = max(u,v);
                        x=1;
            // cout<<l<<" "<<r<<endl;
            for(int j=0;j<factors.size();j++){
                // cout<<factors[j]<<endl;
                x = (x*(l==0?exponents[j][(cf[j][r])]:(exponents[j][(cf[j][r]-cf[j][l-1])])))%p;
            }
            if(l==0){
                x = (x*cpr[r])%p;
                // cout<<cpr[r]<<endl;
            }
            else{
                x = (x*cpr[r])%p;
                x = (x*inv[l-1])%p;
                // cout<<cpr[r]<<" "<<inv[l-1]<<endl;
            }
            // cout<<x<<endl;
            x = (x+1)%p;   
        }
        // cout<<l<<" "<<r<<" "<<x<<endl;
        // cout<<search2(l,r,0,n-1,1)<<endl;
    }
    pf1(x);br;
}
return 0;
}
