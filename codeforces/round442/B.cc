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
char c[10000];
cin>>c;
int s = strlen(c);
int a[s]={0};
if(c[0]=='b') a[0]=1;
f1(i,1,s){
    if(c[i]=='b') a[i] = a[i-1]+1;
    else a[i]=a[i-1];
}
int n=s;
int mn=s+100;
int t,t1,t2;
for(int i=0;i<s;i++){
    for(int j=i;j<s;j++){
        //mid
        t1 = j-i+1;
        if(i==0)
        t=t1-(a[j]-0)+0+(a[n-1]-a[j]);
        else
        t=t1-(a[j]-a[i-1])+a[i-1]+(a[n-1]-a[j]);
        // cout<<i<<" "<<j<<" "<<t<<endl;
        mn = min(mn,t);
    }
}
mn = min(mn,a[n-1]);
cout<<s-mn<<endl;
return 0;
}
