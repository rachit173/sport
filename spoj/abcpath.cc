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
int m,n;
char grid[52][52];
int memo[52][52];
int dir[8][2]={{1,1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
bool check(int x,int y){
  //cout<<x<<" "<<y<<endl;
  if(x>=0&&y>=0&&x<m&&y<n) return true;
  return false;  
}
int dp(int x,int y){
  if(memo[x][y]!=-1) return memo[x][y];
  memo[x][y]=1;
  f(i,8) {
    if(check(x+dir[i][0],y+dir[i][1])&&grid[x+dir[i][0]][y+dir[i][1]]==grid[x][y]+1) memo[x][y] = max(memo[x][y],1+dp(x+dir[i][0],y+dir[i][1]));
  }
  return memo[x][y];
}
int main(){
  RESET(memo,-1);
  int t=1;
  while(1){
    sc(m);sc(n);
    if(m==0&&n==0) break;
    f(i,m) cin>>grid[i];
    RESET(memo,-1);
    int mx=0;
    f(i,m) f(j,n) if(grid[i][j]=='A') mx = max(mx,dp(i,j));
    cout<<"Case "<<t<<": "<<mx<<endl;
    t+=1;
  }
return 0;
}
