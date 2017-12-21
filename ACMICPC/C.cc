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
int a[3][3];
bool check1(int x,int y){
    // cout<<x<<" "<<y<<endl;
    // f(i,3) cout<<a[x][i]<<" ";
    // cout<<endl;
    // f(i,3) cout<<a[y][i]<<" ";
    // cout<<endl;
    if(a[x][0]>=a[y][0]&&a[x][1]>=a[y][1]&&a[x][2]>=a[y][2]){
        // cout<<x<<" "<<y<<endl;
        if(a[x][0]>a[y][0]||a[x][1]>a[y][1]||a[x][2]>a[y][2]){
            // cout<<x<<" "<<y<<endl;
            return true;
        }
        else return false;
    }else{
        return false;
    }
}
bool check(int x,int y,int z){
    // cout<<check1(x,y)<<endl;
    // cout<<check1(y,z)<<endl;
    if(check1(x,y)&&check1(y,z)) return true;
    return false;
}
int main(){
int T;
cin>>T;
while(T--){
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){ sc(a[i][j]);
        }
    }
    if(check(2,1,0)||check(2,0,1)||check(1,0,2)||check(1,2,0)||check(0,1,2)||check(0,2,1)) printf("yes\n");
    else printf("no\n");
}
return 0;
}
