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
int N;
int a[1000][1000];
int age[1000];
int age1[1000];
int mp[1000];
int M;
int I;
int memo[1000];
int dfs(int node){
    if(memo[node]) return oo;
    int mn=oo;
    memo[node]=1;
    for(int i=1;i<=N;i++){
        if(a[node][i]&&!memo[i]) {mn=min(mn,age[i]);
            mn=min(mn,dfs(i));
        }
    }
    return mn;
}
int main(){
    RESET(a,0);
    cin>>N>>M>>I;
    int t,t1,u,v;
    f(i,N) {sc(age[i+1]);age1[i+1]=age[i+1];mp[i+1]=i+1;}
    f(i,M){
        sc(u);sc(v);
        a[v][u]=1;
    }
    char c;
    f(i,I){
        cin>>c;
        if(c=='T'){
            sc(u); sc(v);
            t=age[mp[u]];
            age[mp[u]]=age[mp[v]];
            age[mp[v]]=t;
                        t=mp[u];
            mp[u]=mp[v];
            mp[v]=t;
            

        }else{
            sc(t);
            RESET(memo,0);
            t1=dfs(mp[t]);
            if(t1==oo) cout<<"*\n";
            else cout<<t1<<"\n";
        }
    }
return 0;
}
