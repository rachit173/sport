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
typedef pair<stack<char>,stack<char> > haha;
char s[1000];
stack<char> fun(int start,int end){
  if(s[start]=='(') start++;
  if(s[end]==')') end--;
  int cnt=0;
  stack<char> ret;
  if(start==end){
    ret.push(s[start]);
    return ret;
  }
  int i=start;
  while(i<=end){
    if(s[i]=='('){
      cnt++;
    }
    else if(s[i]==')'){
      cnt--;
    }
    else if(cnt==0 && (s[i]<'a'||s[i]>'z')){
      stack<char> st1 = fun(start,i-1);
      stack<char> st2 = fun(i+1,end);
      ret.push(s[i]);
      while(!st2.empty()){
        ret.push(st2.top());
        st2.pop();
      }
      while(!st1.empty()){
        ret.push(st1.top());
        st1.pop();
      }
    }
    i++;
  }
  return ret;
}
int n;
int main(){
 int T;
 cin>>T;
 while(T--){
   cin>>s;
   n = strlen(s);
   stack<char> ans = fun(0,n-1);
 
 while(!ans.empty())
  {
    printf("%c",ans.top());
    ans.pop();
  }
  br;
 }
return 0;
}
