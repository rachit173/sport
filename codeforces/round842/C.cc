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
int a[10000005];
int ans[21];
void con(int index,int in){
    if(index>10000000) return ;
    a[index]++;
    if(in%2==1) return con(2*index+2,in/2);
    return con(2*index+1,in/2);
}

bool fun(int index,int x,int M){
    if(a[index]==0) return true;
    //cout<<index<<" "<<x<<" "<<M<<endl;
    if(x%2==0){
        if(M%2==0){
            if(a[2*index+1]>0) return fun(2*index+1,x/2,M/2);
            return false;
        }
        else{
            if(a[2*index+1]>0) return fun(2*index+1,x/2,M/2);
            return fun(2*index+2,x/2,M/2);
        }
    }
    else {
        if(M%2==0){
            if(a[2*index+2]>0) return fun(2*index+2,x/2,M/2);
            return false;
        }
        else{
            if(a[2*index+2]>0) return fun(2*index+2,x/2,M/2);
            return fun(2*index+1,x/2,M/2);
        }
    }
}
int bin(int l,int r,int x){
    if(r-l<1) return l;
    int mid = l+(r-l)/2;
    if(fun(0,x,mid)) return bin(l,mid,x);
    return bin(mid+1,r,x);
}
int calc(){
    int ret=0;
    for(int i=21;i>0;i--) cout<<ans[i];
    cout<<endl;
    return ret;
}
int main(){
int n,m;
cin>>n>>m;
int in;
int M=300000;
RESET(a,0);
for(int i=0;i<n;i++){
    sc(in);
    con(0,in);
}
//for(int i=0;i<16;i++) cout<<a[i]<<" ";
//cout<<endl;
int x=0;
int ans[21];
for(int i=0;i<m;i++){
    sc(in);
    x=x^in;
    pf(bin(0,M,x));br;
}
return 0;
}
