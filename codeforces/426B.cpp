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
#define pb push_back
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int n,k;
  char c;
  cin>>n>>k;
  getchar();
  int a[n];
  f(i,n) {scanf("%c",&c); a[i]=c-'A';}
  int opt=0;
  int b[26]={0};
  int t;
  int k1=0;
  ii close[26];
//  f(i,n) cout<<a[i]<<" ";
  //br;
  f(i,26) close[i]=ii(n,i);
  for(int i=0;i<26;i++){
    for(int j=n-1;j>=0;j--) {if(a[j]==i) {close[i]=ii(j,i);break;}}
  }
  sort(close,close+26);
//  f(i,26) cout<<close[i].ff<<" ";
//  br;
  int j=0;
  for(int i=0;i<n&&opt==0;i++){
    t=a[i];
    if(b[t]==0){
      if(k1<k){
      k1++;
      b[t]=1;
      }
      else opt=1;
    }
    if(j<26&&close[j].ff==i){k1--;j++;}
  }
  if(opt==1) cout<<"YES\n";
  else cout<<"NO\n";
return 0;
}
