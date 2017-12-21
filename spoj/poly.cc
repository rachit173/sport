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
ll a[100005][4];
int n;
vector<vector<pll> > memo(21);
int ans[100005];
ll calc(ll x,int ind){
    return a[ind][0]+x*(a[ind][1]+x*(a[ind][2]+x*(a[ind][3])));
}
int main(){
int T;
cin>>T;
while(T--){
    int q;
    sc(n);
    RESET(ans,-1);
    f(i,n){
        sc1(a[i][0]);
        sc1(a[i][1]);
        sc1(a[i][2]);
        sc1(a[i][3]);
    }
    int kw=0;
    int t=1;
    ll x;
    for(int i=0;i<21;i++) memo[i].resize(n);
    // while(t<n+5){
    //     x = t;    
    //     // cout<<t<<endl;  
    //     for(int i=0;i<n;i++){
    //         memo[kw][i] = pll((a[i][0]+x*(a[i][1]+x*(a[i][2]+x*(a[i][3])))),i);
    //         // cout<<memo[kw][i].ff<<endl;
    //     }
    //     sort(memo[kw].begin(),memo[kw].end());
    //     t=t*2;kw++;
    // }
    sc(q);
    int u,v,w;
    while(q--){
        sc1(x);
        if(ans[x]==-1){
            // u=-1;
            // v=x;
            // while(v>0) {
            //    v=v>>1;
            //    u++; 
            // }
            // w = n>>u;
            // f(i,20){
            //     if(w+1<n) w++;
            //     else break;
            // }
            if(n<2001) w=n; 
            ll mn = calc(x,0);
            // int haha=0;
            // cout<<"the index is "<<u<<endl; 
            for(int i=0;i<n;i++){
                // cout<<memo[u][i].ss<<endl;
                    // mn = min(mn,calc(x,memo[u][i].ss));
                    mn = min(mn,(a[i][0]+x*(a[i][1]+x*(a[i][2]+x*(a[i][3])))));
                    // haha=i;
            }
            ans[x] = mn;
            pf(ans[x]);br;
        }else{
            pf(ans[x]);br;
        }
    }
}
return 0;
}
