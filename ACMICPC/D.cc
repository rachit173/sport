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
int isleaf[500005];
void dfs(int x,int pr,ll w,ll h1,ll h2,ll px,ll py){
    w = w+w1[x];
    h1 = h1+hsh[x][0]*p1;
    h2 = h2+hsh[x][1]*p2;
    px = px*p1;
    py = py*p2;
    int cnt1=0;
    for(int i=0;i<(int)g1[x].size();i++){
        if(g1[x][i]!=pr){
            dfs(g1[x][i],x,w,h1,h2,px,py);
        cnt1++;
        }
    }
    if(cnt1) isleaf[x]=0;
    else isleaf[x]=1;
}
int main(){

return 0;
}
