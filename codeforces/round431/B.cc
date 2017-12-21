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
int n;
ll a[10000];
bool check_further(int k,ll c,ll d){
    vi vec;
    cout<<c<<" "<<d<<endl;
    for(int i=0;i<n;i++){
        if(i==k) continue;
        cout<<a[i]<<" "<<a[k]<<i<<" "<<k<<endl;
        if((a[i]-a[k])*d!=c*(i-k)) vec.pb(i);
    }
    f(i,vec.size()) cout<<vec[i]<<" ";
    cout<<endl;
    if(vec.size()==0) return false;
    if(vec.size()==1) return true;
    ll c1= a[vec[1]]-a[vec[0]];
    ll d1 = vec[1] - vec[0];
    for(int i=2;i<vec.size();i++){
        if((a[vec[i]]-a[vec[0]])*d1!=c1*(vec[i]-vec[0])) return false;
    }
    if(c1*d==c*d1) return true;

    return false;
}
bool check(){
    if(n==3){
        if(a[1]-a[0]!=a[2]-a[1]) return true;
        return false;
    }
    ll c,d;
int x = 0;
    for(int k=0;k<2;k++){
    for(int i=k+1;i<n;i++){
        c = a[i] - a[k];
        d = i-k;
        for(int j=i+1;j<n;j++){
          ll c1  = a[j]-a[i];
           ll d1 = j-i;
            if(c1*d==d1*c) x=x| check_further(k,c,d);
        }
    }
}
return x;
}

int main(){
    cin>>n;
    f(i,n) sc1(a[i]);
    ll c,d;
    if(check()){    
        cout<<"Yes";
    }else{
        cout<<"No"<<endl;
    }
return 0;
}
