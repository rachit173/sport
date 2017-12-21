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
using temp_t = std::tuple<ll, ll>;

ll calcInverse(ll a, ll n)
{
    ll t = 0, newt = 1;
    ll r = n, newr = a;  
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
int T;
cin>>T;
while(T--){
    ll a,n;
    sc1(a);
    sc1(n);
    if(n==1){
            pf(1);br;

        continue;
    }
      try {
    ll inverse = calcInverse(a, n);
    // cout << "The multiplicative inverse is " << inverse << endl;
        pf1((n+inverse)%n);br;
}
  catch(exception& e) {
      pf(-1);br;
  }

}
return 0;
}
