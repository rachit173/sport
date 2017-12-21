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
vi vec;
vi ans;
bool check(int x){
    if(x<3) return false;
    int cnt = 0;
    f(i,vec.size()){
        if(x>=vec[i]) break;
        if(x%vec[i]==0){
            cnt++;
            while(x%vec[i]) x/=vec[i];
        } 
    }
    if(x>1) cnt++;
    if(cnt>=3) return true;
    return false;
}
int main(){
int T;
cin>>T;
int primes[100002]={0};
primes[0] = primes[1] = 1;
for(int i=2;i<=100000;i++){
    if(primes[i]==0)
    for(int j=i*2;j<=100000;j+=i) primes[j] = 1;
}
f(i,500) if(primes[i]==0) vec.pb(i);
f(i,vec.size()) cout<<vec[i]<<" ";
cout<<endl;
f1(i,2,100000){
    if(check(i)) ans.pb(i);
}
cout<<ans.size()<<endl;
while(T--){
    int n;
    cin>>n;
    cout<<ans[n-1]<<endl;
}
return 0;
}
