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
class DSU {
    int *rank;
    int size;
    int *p;
public:

    DSU(int n) {
        size = n;
        rank = new int[n+1];
        p = new int[n+1];
        for(int i=0;i<size;i++){
            p[i] = i;
            rank[i] = 0;
        }
    }
    ~DSU() {
        delete [] rank;
        delete [] p;
    }
    void link(int x,int y){
        if(rank[x]>rank[y]) p[y] = find_parent(x); 
        else p[x] = find_parent(y);
        if(rank[x]==rank[y]) rank[y]++;
    }
    int find_parent(int x){
        if(x>=size) return -1;
        if(x!=p[x]) p[x] = find_parent(p[x]);
        return p[x];
    }
    void uni(int x,int y){
        int px = find_parent(x);
        int py = find_parent(y);
        if(px!=py) link(x,y);
    }
};
int main(){
    int n;
    cin>>n;
    DSU d(n);
    int q;
    cin>>q;
    int t;
    while(q--){
        cin>>t;
        if(t==0){
            int x;
            cin>>x;
            cout<<d.find_parent(x)<<endl;;
        }
        else{
            int u,v;
            cin>>u>>v;
            d.uni(u,v);
        }
    }
return 0;
}
