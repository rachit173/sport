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
static const int MAXN = 100004;
static const int MAXW = 100003;
static const int MAXT = 100002;
int n,w,h;
int g[MAXN],p[MAXN],t[MAXN];
vector < int> s[MAXW+MAXT];
int ans_x[MAXN], ans_y[MAXN] ;
int main(){
    sc(n);sc(w);sc(h);
    f(i,n){
        sc(g[i]),sc(p[i]),sc(t[i]);
        s[p[i] - t[i] + MAXT].pb(i);
    }
    vi xs, ys;
    f(i,MAXW+MAXT) if(!s[i].empty()) { 
        for(int u: s[i]){
            if(g[u] == 1) xs.pb(p[u]);
            else ys.pb(p[u]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        sort(s[i].begin(),s[i].end(),[](int u,int v){
            if(g[u] != g[v]) return (g[u] == 2);
            else return (g[u] == 2 ? p[u] > p[v] : p[u]  < p[v]);
        });
        f(j,xs.size()){
            ans_x[s[i][j]] = xs[j];
            ans_y[s[i][j]] = h;
        }
        for(int j = 0; j < ys.size(); ++j) { 
            ans_x[s[i][j+xs.size()]] = w;
            ans_y[s[i][j+xs.size()]] = ys[ys.size() - j - 1];
        }
        xs.clear();
        ys.clear();
    }
    for(int i=0;i<n;i++) printf("%d %d\n",ans_x[i],ans_y[i]);
return 0;
}
