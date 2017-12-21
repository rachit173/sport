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
int n,k;
cin>>n>>k;
string s;
string b="BROKEN";
string sf="SAFE";
int u;
int mn=oo;
int mx=-1;
int mx1=-1;
int mn1=oo;
f(i,n){
    cin>>u;
    cin>>s;
    if(s==b){
        mn = min(mn,u);
        mx1 = max(mx1,u);
    }
    else{
        mx = max(mx,u);
        mn1 = min(mn1,u);
    }

}
if(mx==-1){
    cout<<mn<<" ";
}
else
cout<<mx+1<<" ";
if(mn==oo)
cout<<mx<<endl;
else
cout<<mn-1<<endl;
return 0;
}
