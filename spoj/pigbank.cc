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
int wt[550],cost[550];
int memo[10005];
int main(){
int T;
cin>>T;
while(T--){
    int E,F,W;
    sc(E); sc(F);
    W = F-E;
    int N;
    sc(N);
    f(i,N) {
        sc(cost[i]);
        sc(wt[i]);
    }
    f(i,W+2) memo[i] = oo;
    memo[0] = 0;
    for(int i=1;i<=W;i++){
        for(int j=0;j<N;j++){
            if(i-wt[j]>=0){
                memo[i] = min(memo[i],memo[i-wt[j]]+cost[j]);
            }
        }
    }
    /*
    int aux[W+3];
        for(int j=0;j<N;j++){
            for(int i=0;i<=W;i++){
                if(i-wt[j]>=0){
                    aux[i] = min(memo[i],memo[i-wt[j]]+cost[j]);
                }
                else
                    aux[i] = memo[i];
            }
            f(i,W+2) memo[i] = aux[i];
        }
    */
    if(memo[W]<oo-5)
    cout<<"The minimum amount of money in the piggy-bank is "<<memo[W]<<".\n";
    else 
    cout<<"This is impossible.\n";
}
return 0;
}
