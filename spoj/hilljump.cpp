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
ll seg[500000];
ll seg1[500000];
int N,C;
ll search(int l,int r,int st,int en,int index){
    //cout<<l<<" "<<r<<" "<<st<<" "<<en<<" "<<seg[index]<<" "<<seg1[index]<<endl;
    int mid=st+(en-st)/2;
    if(r-l<1) return 0;
    if(l==st && r==en) return (r-l)*seg[index]+seg1[index];
    if(r<=mid) return (r-l)*seg[index]+search(l,r,st,mid,2*index);
    else if(mid<=l) return (r-l)*seg[index]+search(l,r,mid,en,2*index+1);
    else return (r-l)*seg[index]+search(l,mid,st,mid,2*index)+search(mid,r,mid,en,2*index+1);
}
void update(int l,int r,int st,int en,int index,int val){
    //cout<<l<<" "<<r<<" "<<st<<" "<<en<<endl;
    if(r-l<1) return;
    if(l==st && r==en){
        seg[index]+=(ll)val;
        return;
    }
    int mid=st+(en-st)/2;
    seg1[index]+=((ll)(r-l)*(ll)(val));
    if(r<=mid) {
        update(l,r,st,mid,2*index,val);
    }
    else if(mid<=l){
        update(l,r,mid,en,2*index+1,val);
    }
    else{
        update(l,mid,st,mid,2*index,val);
        update(mid,r,mid,en,2*index+1,val);
    }
}
int main(){
    int T;
    cin>>T;
while(T--){
RESET(seg,0);
RESET(seg1,0);
sc(N);sc(C);
int t,u,v,val;
f(i,C){
sc(t);sc(u);sc(v);
if(t==0){
    sc(val);
    u--;
    update(u,v,0,N,1,val);
}
else{
    u--;
    pf1(search(u,v,0,N,1));br;
}
}
}
return 0;
}
