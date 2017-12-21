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
int a[100005];
int b[100005];
ll memo[100005];
int main(){
    int N,Q;
    cin>>N>>Q;
    RESET(memo,-1);
    f(i,N) sc(a[i]);
    b[0]=a[0];
    f1(i,1,100001) b[i] = b[i-1]^a[i];
    int t,i,x,k;
    while(Q--){
        sc(t);
        if(t==1){
            sc(i);sc(x);
            
        }
        else{
            sc(i);sc(k);

        }
    }
return 0;
}
