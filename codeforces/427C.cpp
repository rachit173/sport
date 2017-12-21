#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sc1(a) scanf("%lld",&a);
#define pf1(a) printf("%lld",a);
#define sc2(a) scanf("%d %d",&a.first,&a.second);
#define br printf("\n");
#define sp printf(" ");
#define ll long long int
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef struct star{
  int x;
  int y;
  int s;
}star;
int main(){
  int n,q,c;
  cin>>n>>q>>c;
  star a[n];
  for(int i=0;i<n;i++) {sc(a[i].x);sc(a[i].y);sc(a[i].s);}
  int memo[101][101];
  int memo1[101][101][12];
  RESET(memo,0);
  RESET(memo1,0);
  int u,v,s;
  for(int i=0;i<n;i++){
    u=a[i].x; v=a[i].y; s=a[i].s;
    for(int j=v;j<=100;j++) memo[u][j]+=s;
    for(int j=v;j<=100;j++) memo1[u][j][s]++;
  }
  int t,x1,y1,x2,y2;
  while(q--){
    sc(t);sc(x1);sc(y1);sc(x2);sc(y2);
    int ans=0;
    int num1=0;
    int num2=0;
    t=t%(c+1);
    for(int i=x1;i<=x2;i++){ ans+=(memo[i][y2]-memo[i][y1-1]);  }
    for(int i=x1;i<=x2;i++){
      for(int j=0;j<(c+1-t);j++)
      num1+=(memo1[i][y2][j]-memo1[i][y1-1][j]);
      for(int j=c+1-t;j<=c;j++)
      num2+=(memo1[i][y2][j]-memo1[i][y1-1][j]);
    }
    ans=ans+num1*(t)-num2*(c+1-t);
    pf(ans);
    br;
  }
return 0;
}
