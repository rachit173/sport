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
int a[n];
f(i,n) sc(a[i]);
sort(a,a+n);
int b[n]={0};
int ct=0;
int i=n-1;
int ans=0;
int prev=oo;
while(ct<n){
    if(b[i]!=1&&a[i]<prev){
        // cout<<i<<" "<<b[i]<<" "<<a[i]<<" "<<prev<<endl;
       b[i]=1;
       ct++;
       if(ct==n){
           ans++;
           break;
       }
       prev=a[i]; 
    }
    if(i==0) {
        ans++;
        prev=oo;
    }
    i = (i-1+n)%n;
}
cout<<ans<<endl;
return 0;
}