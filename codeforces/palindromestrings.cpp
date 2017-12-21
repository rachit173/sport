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
int memo[10000][10000];
int memo1[10000][10000];
int n;
char s[10000];
inline void print(int i,int j){
  for(;i<=j;i++) printf("%c",s[i]);
}
int dp(int st,int en){
  if(memo[st][en]!=-1) return memo[st][en];
  if(en<=st){
    memo[st][en]=1;
    return memo[st][en];
  }
  memo[st][en]=(s[st]==s[en])?dp(st+1,en-1):0;
  return memo[st][en];
}
int dp1(int st,int en){
  if(memo1[st][en]!=-1) return memo1[st][en];
  if(en<=st){
    memo1[st][en]=1;
    return memo1[st][en];
  }
  if(st==en-1){
    if(s[st]==s[en])
    memo1[st][en]=2;
    else memo1[st][en]=0;
    return memo1[st][en];
  }
  int len=(en-st+1);
  len=len/2;
  int l=dp1(st,st+len-1);
  int r=dp1(en-len+1,en);
  if(l!=r) memo1[st][en]=(memo[st][en]==1)?1:0;
  else{
    memo1[st][en]=(memo[st][en]==1)?l+1:0;
  }
  return memo1[st][en];
}
int main(){
RESET(memo,-1);
RESET(memo1,-1);
cin>>s;
n=strlen(s);
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++)
  memo[i][j]=(memo[i][j]==-1)?dp(i,j):memo[i][j];
}
//f(i,n){
//  for(int j=i;j<n;j++)
//    memo1[i][j]=(memo1[i][j]==-1)?dp1(i,j):memo1[i][j];
//}
int a[10000]={0};
//return 0;
//cout<<dp(0,2)<<endl;
for(int i=0;i<n;i++){
  for(int j=i;j<n;j++){
    //cout<<dp1(i,j)<<endl;
    a[(dp1(i,j))]++;
  }
}
//printing the answer
for(int i=1;i<=n;i++){pf(a[i]);sp;}
br;
return 0;
}
