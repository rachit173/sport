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
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod 1000000007
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll A[32][3][3];
ll base[3][3]={{2,1,0},{0,0,1},{-1,0,0}};
ll I[3][3]={{1,0,0},{0,1,0},{0,0,1}};
void mult(ll Arr[3][3],ll B[3][3],ll C[3][3]){
  f2(i,j,3,3) C[i][j]=0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
        C[i][j]=(C[i][j]+Arr[i][k]*B[k][j]+mod)%mod;
}
ll fun(int n){
if(n<=0) return 0;
if(n==1) return 1;
if(n==2) return 2;
n=n-1;
ll tmp[3][3];
mult(I,I,tmp);
int i=0;
ll tmp1[3][3];
while(n>0){
  if(n%2==1) {mult(tmp,A[i],tmp1);
    f2(x,y,3,3) tmp[x][y]=tmp1[x][y];
  }
  n=n/2;
   i++;
}
return tmp[0][0];
}
int main(){
  mult(base,I,A[0]);
  for(int i=1;i<32;i++){
    mult(A[i-1],A[i-1],A[i]);
  }
//  ll tmp[3][3];
//  mult(I,I,tmp);
//  cout<<tmp[0][0]<<" "<<tmp[0][1]<<" "<<tmp[0][2]<<" "<<tmp[1][1]<<endl;
//  for(int k=0;k<32;k++){
//    for(int i=0;i<3;i++){
  //    for(int j=0;j<3;j++) {pf1(A[k][i][j]);sp;}
//      br;
//    }
//    br;
//  }
//  ll tmp[3][3];
  int T;
  cin>>T;
  int N,M;
  while(T--){
    cin>>N>>M;
    pf1((fun(M)-fun(N-1)+mod)%mod);br;
  }
return 0;
}
