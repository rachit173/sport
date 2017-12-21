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
typedef struct tri{
  map<char,struct tri*> arr;
}tri;
tri* build(tri* root,char *s,int index){
  //if(s[index]!='\0') cout<<s[index]<<endl;
  if(root==NULL){
    root = new tri;
  }
  if(s[index]=='\0') {return root;}
  root->arr[s[index]] = build(root->arr[s[index]],s,index+1);
  return root;
}
int dfs(tri* root){
  if(root==NULL) return 0;
  int ret=1;
  for(auto e:root->arr) ret+=dfs(e.ss);
  return ret;
}
int main(){
  int tc;
  cin>>tc;
  while(tc--){ 
    char s[1005];
    cin>>s;
    tri* root = NULL;
    int sz = strlen(s);
    //cout<<sz<<endl;
    f(i,sz) root = build(root,s,i); 
    cout<<dfs(root)-1<<endl; 
  }
return 0;
}
