#include<bits/stdc++.h>
using namespace std;
#define swap(a,b) {int v=a;a=b;b=v;}
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
int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    int a[N];
    f(i,N) sc(a[i]);
    int ct[100005]={0};
    f(i,N) ct[a[i]]++;
    vii vec;
    f(i,100005) if(ct[i]!=0) vec.pb(ii(ct[i],i));
    sort(vec.begin(),vec.end());
    // return 0;
    vi haha;
    f(i,vec.size()) f(j,vec[i].ff) haha.pb(vec[i].ss);
    vector<stack<int> >AL(100005);
    // return 0;
    haha.pb(haha[0]);
    for(int i=N;i>=0;i--){
        if(i>=3) swap(haha[i],haha[i-1]);
        i--;
    }
    haha[0]=haha[N];
    for(int i=N;i>0;i--){
        AL[haha[i]].push(haha[i-1]);
    }
    int b[N];
    int ans=0;
    f(i,N){
        b[i] = AL[a[i]].top();
        AL[a[i]].pop();
        if(a[i]!=b[i]) ans++;
    }
    pf(ans);
    br;
    f(i,N){
        pf(b[i]);
        sp;
    }
    br;
}
return 0;
}
