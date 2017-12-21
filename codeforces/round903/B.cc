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
int main(){
int h1,a1,c1;
cin>>h1>>a1>>c1;
int h2,a2;
cin>>h2>>a2;
int ans=0;
vector<string> v;
while((ceil(h1/(a2*1.0)))*a1<h2){
    h1+=c1;
    // cout<<"HEAL\n";
    v.pb("HEAL");
    h1-=a2;
}
// cout<<h1<<endl;
while(h2>0){
    if(h1>a2||h2<=a1){
        h2-=a1;
        v.pb("STRIKE");
    }
    else{
        h1+=c1;
        v.pb("HEAL");
    }
    h1-=a2;
}
cout<<v.size()<<endl;
f(i,v.size()) cout<<v[i]<<endl;
return 0;
}
