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
int a[500000];
int seg[500000];
int update(int x,int ind,int l,int r,int base){
  if(r<=l) {
    seg[base]+=x;
    return seg[base];
  }
  int mid = l+(r-l+1)/2;
  if(ind<mid){
    seg[base] = max(update(x,ind,l,mid-1,2*base),seg[2*base+1]);
    return seg[base];
  }
  if(ind>=mid){
    seg[base] = max(seg[2*base],update(x,ind,mid,r,2*base+1));
    return seg[base];
  }
}
int search(int l,int r,int st,int en,int base)
{ 
  int mid = l+(r-l+1)/2;
  //if(en<=st) return seg[base];
  //cout<<l<<" "<<r<<" "<<st<<" "<<en<<" "<<mid<<" "<<base<<endl;
  if(l==st&&r==en){
    return seg[base];
  }
  if(en<mid){
    return search(l,mid-1,st,en,2*base);
  }
  if(st>=mid){
    return search(mid,r,st,en,2*base+1);
  }
  return max(search(l,mid-1,st,mid-1,2*base),search(mid,r,mid,en,2*base+1));
}
int main(){
  map<int,set<int> > mp;

int N;
sc(N);
char c;
RESET(a,-1);
f1(i,1,N+1){ sc(a[i]);
  mp[a[i]].insert(i);
}
//for(auto e:mp) sort(e.ss.begin(),e.ss.end());
int x,y;
f1(i,1,N+1){
  update(a[i],i,1,N,1);
}
int M;
sc(M);
while(M--){
  scanf("\n%c",&c);
  if(c=='U'){
     sc(x);sc(y);
     mp[a[x]].erase(x);
     mp[y].insert(x);
     update(y-a[x],x,1,N,1);
    a[x] = y;
  }
  else{
    sc(x);sc(y);
    //cout<<x<<" "<<y<<endl;
    int mx = search(1,N,x,y,1);
    //cout<<mx<<endl;
    //for(auto v:mp[mx]) cout<<v<<endl;
    
    set<int> &arr = mp[mx];
    auto e = arr.upper_bound(y);
    e--;
    //cout<<(*e)<<endl; 
    int ind  = (*e);
    int mx1 = -1;
    if(x<ind)
     mx1 = max(mx1,search(1,N,x,ind-1,1));
    if(ind<y)
      mx1 = max(mx1,search(1,N,ind+1,y,1));
      pf(mx1+mx);br;
  }
}
return 0;
}
