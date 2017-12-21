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
bool check(char *s,char c){
  int sz=strlen(s);
  f(i,sz) if(s[i]!=c) return false;
  return true;
  }
int main(){
int n,m;
cin>>n>>m;
char a[n][m+1];
char b[m][n+1];
f(i,n) cin>>a[i];
//cout<<check(a[0],'R');
f(i,n){
f(j,m){
b[j][i]=a[i][j];
}
}
f(i,m) b[i][n]='\0';
//f(i,m) cout<<b[i]<<endl;
int opt1=0;
int opt=0;
if(n%3==0){
int x[3]={0,0,0};
char type=a[0][0];
if(type=='R')
  x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=0;i<n/3;i++){
  if(check(a[i],type)==false) opt=1;
}
type=a[n/3][0];
if(type=='R')
  x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=n/3;i<(2*n/3);i++)
  if(check(a[i],type)==false) opt=1;

type=a[(2*n/3)][0];
if(type=='R')
  x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=(2*n/3);i<n;i++)
  if(check(a[i],type)==false) opt=1;
  if((x[0]==0)||(x[1]==0)||(x[2]==0)) opt=1;
}
if(m%3==0){
int x[3]={0,0,0};
char type=b[0][0];
if(type=='R') x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=0;i<m/3;i++){
  if(check(b[i],type)==false) opt1=1;
}
type=b[m/3][0];
if(type=='R') x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=m/3;i<(2*m/3);i++){
  if(check(b[i],type)==false) opt1=1;
}
type=b[(2*m/3)][0];
if(type=='R') x[0]++;
  else if(type=='B') x[1]++;
  else x[2]++;
for(int i=(2*m/3);i<m;i++){
  if(check(b[i],type)==false) opt1=1;}
  //cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  if((x[0]==0)||(x[1]==0)||(x[2]==0)) opt1=1;
}
//cout<<opt<<" "<<opt1<<endl;
if(opt==0&&n%3==0){

cout<<"YES"<<endl;
}
else if(opt1==0&&m%3==0){

cout<<"YES"<<endl;
}
else{
  cout<<"NO"<<endl;
}
return 0;
}