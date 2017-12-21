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
ll grid[103][103];
ll aux[103][103];
int n,m;
void wrap(){
    for(int i=1;i<=m;i++){
        grid[0][i]=grid[n][i];
        grid[n+1][i]=grid[1][i];
    }
    for(int i=1;i<=n;i++){
        grid[i][0]=grid[i][m];
        grid[i][m+1]=grid[i][1];
    }
    grid[0][0]=grid[n][0];
    grid[n+1][0]=grid[1][0];
    grid[0][m+1]=grid[n][m+1];
    grid[n+1][m+1]=grid[1][m+1];
}
void blur(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            aux[i][j] = grid[i][j]+grid[i+1][j+1]+grid[i+1][j]+grid[i+1][j-1]+grid[i][j+1]+grid[i-1][j+1]+grid[i-1][j]+grid[i][j-1]+grid[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            grid[i][j]=aux[i][j];
        }
    }
}
int main(){
    int w,h,b;
    cin>>w>>h>>b;
    n=h;
    m=w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)
        sc1(grid[i][j]);
    }
    for(int i=0;i<b;i++){
        wrap();
    //     for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=m+1;j++) cout<<grid[i][j]<<" ";
    //         cout<<endl;
    // }        
        blur();
    }
    set<int> s;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) s.insert(grid[i][j]);
    cout<<s.size()<<endl;
return 0;
}
