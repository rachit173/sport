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
void fun(int u,int v){
    if(v<u) return;
    if(v==u){
        printf("%d ",u);
        return;
    } 
    int mid = u + (v-u+1)/2;
    printf("%d ",mid);
    fun(u,mid-1);
    fun(mid+1,v);
    printf("%d ",mid);
}
int fun1(int u,int v){
    if(v<u) return 0;
    if(v==u){
        return 1;
    } 
    int mid = u + (v-u+1)/2;
    return 2+fun1(u,mid-1)+fun1(mid+1,v);
}
int main(){
int n;
cin>>n;
pf(fun1(1,n));br;
fun(1,n);
return 0;
}
