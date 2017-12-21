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
    int a=0,b=0,c=0;
    int ans=1;
    sc(n);
    int nm,dnm;
    f(i,n){
        scanf("%d/%d",&nm,&dnm);
        if(nm==1&&dnm==4) a++;
        else if(nm==1&&dnm==2) b++;
        else c++;
    }
    ans+=(b/2);
    b=b%2;
    a=a-c-2*b;
    if(a<=0) {
        ans+=(c+b);
    }
    else{
        ans+=(c+b+ceil(a/4.0));
    }
    cout<<ans<<endl;
return 0;
}
