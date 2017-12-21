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
ll segmentUnionLength(const vii &seg){
    int n = seg.size();
    vector<pair<int,bool> > points(n*2);
    for(int i=0;i<n;i++){
        points[i*2] = ii(seg[i].ff,false);
        points[i*2+1] = ii(seg[i].ss,true);
    }
    sort(points.begin(),points.end());
    int Counter = 0;
    ll result = 0;
    for(unsigned i=0;i<2*n;i++){
        if(Counter){
            result+=(ll)(points[i].ff - points[i-1].ff);
        }

        (points[i].ss)?Counter--:Counter++;
    }
    return result;
}
int main(){
// takin the endpints of segments lying on the x axis
    int N;
    cin>>N;
    vii segs(N);
    f(i,N) {
        sc2(segs[i]);
    }
    cout<<segmentUnionLength(segs)<<endl;
return 0;
}
