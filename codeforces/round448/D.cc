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
ll memo[1000005][2];

long long calcInverse(long long a, long long n)
{
    long long t = 0, newt = 1;
    long long r = n, newr = a;  
    while (newr != 0) {
        auto quotient = r /newr;
        tie(t, newt) = make_tuple(newt, t- quotient * newt);
        tie(r, newr) = make_tuple(newr, r - quotient * newr);
    }
    if (r > 1)
        throw runtime_error("a is not invertible");
    if (t < 0)
        t += n;
    return t;
}

int main(){
    //preprocessing
    RESET(memo,0);
    memo[0][0]=memo[0][1] = 1;
    for(int i=1;i<=1000000;i++){
        memo[i][0] = (memo[i-1][0]*i)%mod;
        memo[i][1] = calcInverse(memo[i][0],mod);
    }
string gaga,haha;
cin>>gaga>>haha;
int a[26]={0};
for(auto e in gaga) a[e-'a']++;
f(i,haha.size()){
   int t=0;
   for(i,haha[i]-'a'){
       if(a[i]==0) continu
   }

    if(a[haha[i]-'a']<=0) break;
    else {
        a[haha[i]-'a']--;
    }
}
return 0;
}
