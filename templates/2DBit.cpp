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
#define f2(i,st,n) for(int i=st;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll a[10005][10005];
//ll aux[10005][10005];
ll Bit[10006][10006];
int n=100,m=1000;
void update(ll val,int x,int y){
  int tmp=y;
  for(;x<=n;x+=(x&(-x))){
    y=tmp;
    for(;y<=m;y+=(y&(-y)))
      Bit[x][y]+=val;
  }
}
ll search(int x,int y){
  if(x<=0||y<=0){
    return 0;
  }
  int x1=x-(x&(-x))+1;
  int y1=y-(y&(-y))+1;
  ll sum=0;
//  for(;x>0;x-=(x&(-x)))
  //  for(;y>0;y-=(y&(-y)))
    //  sum+=Bit[x][y];
  //return sum;
  return Bit[x][y]+search(x1-1,y)+search(x,y1-1)-search(x1-1,y1-1);
}
int main(){
sc(n);sc(m);
RESET(a,0);
RESET(Bit,0);
f2(i,1,n+1) f2(j,1,m+1) sc1(a[i][j]);
f2(i,1,n+1) f2(j,1,m+1) update(a[i][j],i,j);//update(a[i][j]-search(i,j)-search(i-1,j-1)+search(i,j-1)-search(i-1,j),i,j);
int q;
sc(q);
int t;
ii p1,p2;
ll val;
while(q--){
  sc(t);
  if(t==0){
    sc2(p2);sc2(p1);
    pf1(search(p1.ff,p1.ss)+search(p2.ff-1,p2.ss-1)-search(p1.ff,p2.ss-1)-search(p2.ff-1,p1.ss));br;
  }
  else{
    sc2(p1); sc1(val);
    update(val-a[p1.ff][p1.ss],p1.ff,p1.ss);
  }
}
return 0;
}
