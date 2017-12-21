#include<bits/stdc++.h>
using namespace std;
#define oo 1000000009
#define sc(a) scanf("%d",&a);
#define sc2(a) scanf("%lld",&a);
#define sc3(a) scanf("%llf",&a);
#define pf(a) printf("%d",a);
#define pf2(a) printf("%lld",a);
#define br printf("\n");
#define ll long long int
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))

typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
int T;
cin>>T;
while(T--){
int N,K;
sc(N);sc(K);
int a[N];
f(i,N) sc(a[i]);
sort(a,a+N);
int d=oo;
f(i,N-K+1) d=min(d,a[i+K-1]-a[i]);
pf(d);
br;
}
return 0;
}
