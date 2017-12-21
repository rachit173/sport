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
#define oo 1000000009
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
char s[2500];
ll memo[2001][2001];
int n;
ll dp(int st,int en){
  if(memo[st][en]!=-1) return memo[st][en];
  //if((en-st+1)%2==1) {memo[st][en]; return oo;}
  if(st>en) {memo[st][en]=0; return 0;}
  //first two letters
  memo[st][en]=dp(st+2,en)+(s[st]!='{')+(s[st+1]!='}');
  //last two letters
  memo[st][en]=min(memo[st][en],dp(st,en-2)+(s[en-1]!='{')+(s[en]!='}'));
  //first and last letter
  memo[st][en]=min(memo[st][en],dp(st+1,en-1)+(s[st]!='{')+(s[en]!='}'));
  return memo[st][en];
}
int main(){
  int i=0;
  while(1){
  cin>>s;
  i++;
  if(s[0]=='-') break;
  n=strlen(s);
  RESET(memo,-1);
  printf("%d. %lld\n",i,dp(0,n-1));
  }
return 0;
}
