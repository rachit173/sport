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
// typedef vector<string,int> si;
typedef struct si{
    string first;
    int second;
    si(string s,int t):first(s),second(t) {

    }
}si;
bool cmp(si a,si b){
    if(a.ff!=b.ff) return a.ff<b.ff;
    return a.ss<b.ss;
}
int main(){
int n;
cin>>n;
char c;
char str[(n+1)*26][51];
int key;
string rev,style;
char f[60];
int kw=0;
int haha=1;
scanf("\n%c",&c);
while(c!='\n'){
    f[kw++]=c;
    if(c==' ') haha++;
    scanf("%c",&c);
}
f[kw++]='\0';
// cout<<haha<<endl;
char sarr[n*haha+2][51];
int k=0;
for(int i=0;k<kw&&i<haha;i++){
    int j=0;
    // cout<<f[k];
    while(f[k]!='\0'&&f[k]!=' '){
        sarr[i][j] = f[k];
        k++;
        j++;
    }
    k++;
    sarr[i][j]='\0';
}
for(int i=haha;i<n*haha;i++){
    scanf("%s",sarr[i]);
}
vector<string> store;
for(int i=0;i<51;i++){
    store.pb(string(i,'0'));
}
cin>>key>>rev>>style;
// cout<<haha<<endl;
key--;
string s2;
// for(int i=0;i<n*haha;i++) cout<<sarr[i]<<endl;
vector<si> vec;
for(int i=key;i<n*haha;i+=haha) {vec.pb(si(sarr[i],i/haha));}
if(style=="numeric"){
    int mx=50;
    // for(int i=0;i<vec.size();i++) mx = max((int)vec[i].ff.size(),mx);
    for(int i=0;i<vec.size();i++){
        s2 = store[(mx-vec[i].ff.size())]+vec[i].ff;
        vec[i] = si(s2,vec[i].ss);
    }
}
sort(vec.begin(),vec.end(),cmp);
// cout<<rev<<endl;
if(rev=="true") reverse(vec.begin(),vec.end());
int v;
for(int i=0;i<vec.size();i++){
    v = vec[i].ss;
    // cout<<vec[i].ff<<":";
    for(int j=0;j<haha;j++)
        printf("%s ",sarr[j+v*haha]);
    br;
}
return 0;
}
