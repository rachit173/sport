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
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
char s[2005];
int n;
int k=0;
while(1){
  scanf("%s",s);
  k++;
  if(s[0]=='-') break;
  n=strlen(s);
  stack<char> st;
  int i=n-1;
  int ans=0;
  while(i>=0){
    if(s[i]=='{'){
      if(st.empty()) {ans++;st.push('}');}
      else st.pop();
    }
    else st.push('}');
    i--;
  }
  int p=st.size()/2;
  printf("%d. %d\n",k,ans+p);
}
return 0;
}
