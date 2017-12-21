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
int n,m;
char grid[101][102];
int aux1[102][102];
int aux2[102][102];
int main(){
    int t=0;
    f(i,101){
        f(j,101){
            aux1[i][j] = t;
            t=t^1;
            aux2[i][j] = t;
        }
        t = aux1[i][0]^1;
    }
   int T;
   cin>>T;
   while(T--){
       cin>>n>>m;
       f(i,n) scanf("%s",grid[i]);
       int c1=0;
       f(i,n){
           f(j,m){
               if(grid[i][j]=='R'&&aux1[i][j]==1){
                c1+=5;
            }
            else if(grid[i][j]=='G'&&aux1[i][j]==0){
                c1+=3;
            }
           }
        }
        int c2=0;
               f(i,n){
           f(j,m){
               if(grid[i][j]=='R'&&aux2[i][j]==1){
                c2+=5;
            }
            else if(grid[i][j]=='G'&&aux2[i][j]==0){
                c2+=3;
            }
           }
        }
        cout<<min(c1,c2)<<endl;
   }
return 0;
}
