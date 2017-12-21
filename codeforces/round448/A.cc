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
int n;
cin>>n;
int a[2*n];
f(i,n) sc(a[i]);
f(i,n) a[i+n] = a[i];
int b[2*n];
b[0]=a[0];
f(i,2*n) b[i] =a[i]+b[i-1];
int x,y;
int mn=abs(180-a[0]);
for(int i=1;i<2*n;i++){
    for(int j=i;j<2*n;j++){
        if(j-i+1>=n) continue;
        mn = min(mn,abs(180-(b[j]-b[i-1])));
    }
}
f(i,n) mn = min(mn,abs(180-(b[i])));
f(i,n) mn = min(mn,abs(180-(a[i])));
cout<<2*mn<<endl;
return 0;
}
