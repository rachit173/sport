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
ll p,n,q;
ll seg2[3000007];
ll a[1000007];
ll b[1000007];
//segment tree for range sum query 
void update2(int index,int l,int r,ll val,int base){
    if(r<=l){
        seg2[base] =val%p;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update2(index,l,mid-1,val,2*base);
        seg2[base] = (seg2[2*base]*seg2[2*base+1])%p;
    }else{
        update2(index,mid,r,val,2*base+1);
        seg2[base] = (seg2[2*base]*seg2[2*base+1])%p;
    }
}
ll search2(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg2[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search2(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search2(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg2[base];
    return (search2(start,mid-1,l,mid-1,2*base)*
                search2(mid,end,mid,r,2*base+1))%p;
}
int main(){
int T;
cin>>T;
while(T--){
    sc1(n);
    sc1(p);
    sc1(q);
    f(i,3*n+2) seg2[i]=1;
    f(i,n){
        sc1(a[i]);
        update2(i,0,n-1,a[i],1);
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
            x = search2(l,r,0,n-1,1)%p;
            x = (x+1)%p;   
        }
        else {
            u = (l+x)%n;
            v = (r+x)%n;
            l = min(u,v);
            r = max(u,v);
            x = search2(l,r,0,n-1,1)%p;
            x = (x+1)%p;
        }
        // cout<<l<<" "<<r<<" "<<x<<endl;
        // cout<<search2(l,r,0,n-1,1)<<endl;
    }
    pf1(x);br;
}
return 0;
}
