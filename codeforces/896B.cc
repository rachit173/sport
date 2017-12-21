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
int n;
int a[2000];
bool check()
{
  f(i,n) if(a[i]==-1) return false;
  return true;
}
int bin(int x,int st,int en){
  if(st==en) return en;
  //int mid = (l+r+1)/2;
  int mid1 = (st+en+1)/2;
  if(a[mid1]==-1) return mid1;
  if(a[mid1]==x) return mid1;
  if(x>a[mid1]) return bin(x,mid1+1,en);
  else return bin(x,st,mid1-1);
}
int main()
{
  int m,c;
  sc(n);
  sc(m);
  sc(c);
  RESET(a,-1);
  int p;
  int haha=0;
  while(!check()&&haha<m){
    sc(p);
    haha++;
    int ind = bin(p,0,n-1);
    if(a[ind]==-1) {
      a[ind]=p;
      pf(ind+1);br;
      fflush(stdout);
    }
    else{
      int ans;
      int i=ind+1;
      int c1=0,d1=0,c2=0,d2=0;
      while(i<n){
        if(a[i]<=p){
          c1++;
          if(a[i]!=-1) d1++;
        }
        i++;
      }
      i=ind-1;
      while(i>=0){
        if(a[i]<=p){
            c2++;
            if(a[i]!=-1) d2++; 
        }
        i--;
      }
      if(c1*d2>=d1*c2){
        //right side
        if(c1>d1){
            ans = ind+d1+1;
            a[ans]=p;
        }
        else{
            //equal
            ans = ind+d1;
            a[ans] = p;
        }
      }
      else{
        //left side
        if(c2>d2){
          ans = ind-d1-1;
          a[ans] = p;
        }
        else{
          ans = ind-d1;
          a[ans] = p;
        }
      }
      pf(ans+1);br;
      fflush(stdout);
    }
    fflush(stdout);
  }
  return 0;
}
