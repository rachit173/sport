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
typedef pair<int,ii> iii;
int main(){
int n,m,k;
cin>>n>>m>>k;
int grid[n+2][m+2];
int aux[n+2][m+2];
RESET(grid,0);
RESET(aux,-1);
char c[n+1][m+2];
f(i,n) scanf("%s",c[i]);
f(i,n){
    f(j,m){
        if(c[i][j]=='.') grid[i+1][j+1]=0;
        else grid[i+1][j+1]=1;
    }
}
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
f(i,n+2) grid[i][0]=1;
f(i,n+2) grid[i][m+1]=1;
f(i,m+2) grid[0][i]=1;
f(i,m+2) grid[n+1][i]=1;
// f(i,n+2){
//     f(j,m+2){
//         pf(grid[i][j]);
//     }
//     br;
// }
int x1,y1,x2,y2;
int x,y,u,v;
cin>>x1>>y1>>x2>>y2;
priority_queue<ii,vector<ii>,greater<ii> > pq;
pq.push(ii(0,x1+y1*1007));
aux[x1][y1]=0;
int ans=-1;
while(!pq.empty()){
    ii tmp = pq.top();
    pq.pop();
    int tm = tmp.ff;
    x = tmp.ss%1007;
    y = tmp.ss/1007;
    // if(aux[x][y]==1) continue;
    // cout<<x<<" "<<y<<endl;
    if(x==x2&&y==y2){
        ans = tm;
        break;
    }
    f(i,4){
        for(int j=1;j<=k;j++){
            u = x+j*dir[i][0];
            v = y+j*dir[i][1];
            // cout<<x<<" "<<y<<" "<<u<<" "<<v<<" "<<aux[u][v]<<" "<<grid[u][v]<<endl;
            if(aux[u][v]==-1&&grid[u][v]==0){
                aux[u][v]=tm+1;
                pq.push(ii(tm+1,u+v*1007));
            }
            else if(grid[u][v]==1)break;
            else if(aux[x][y]==aux[u][v]) break;
        }
    }
}
printf("%d\n",ans);
return 0;
}
