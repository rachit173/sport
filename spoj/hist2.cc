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
while(1){
    int n;
    cin>>n;
    if(n==0) break;
    int a[n];
    f(i,n) sc(a[i]);
    vi b(n);
    f(i,n) b[i] = i;
    int ans =0 ;
    int cnt = 0;
    do{
        int ret = 0;
        ret+=(a[b[0]]+a[b[n-1]]);
        ret+=2*n;
        f(i,n-1){
            ret+=abs(a[b[i+1]]-a[b[i]]);
        }
        // f(i,b.size()) cout<<b[i]<<" ";
        // cout<<" : ";
        // cout<<ret<<endl;
        if(ret>ans){
            ans = ret;
            cnt = 1;
        }
        else if(ret==ans){
            cnt++;
        }
    }while(next_permutation(b.begin(),b.end()));
    pf(ans);sp;pf(cnt);br;
}
return 0;
}
