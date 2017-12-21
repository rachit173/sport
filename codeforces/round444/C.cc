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
int  a[26];
bool check(int x[8][2],int p){
    int b[26];
    // pf(p);br;
    f(i,26) b[i]=a[i];
    for(int i=0;i<8;i++){
        int t=x[i][0];
        int t1 = x[(i+p+8)%8][0];
        // cout<<t<<" "<<t1<<endl;
        b[t]=a[t1];
    }
    for(int i=0;i<6;i++)
    {
        if(b[4*i+1]!=b[4*i+2]) return false;
        if(b[4*i+2]!=b[4*i+3]) return false;
        if(b[4*i+3]!=b[4*i+4]) return false;
        if(b[4*i+4]!=b[4*i+1]) return false;

    }
    return true;
}
int main(){
f1(i,1,25) cin>> a[i];
int x[8][2];
int y[8][2];
int z[8][2];
x[0][0]= 9;
x[1][0]= 10;
x[2][0]= 19;
x[3][0]= 17;
x[4][0]= 4;
x[5][0]= 3;
x[6][0]= 14;
x[7][0]= 16;
//
x[0][1]= 11;
x[1][1]= 12;
x[2][1]= 20;
x[3][1]= 18;
x[4][1]= 2;
x[5][1]= 1;
x[6][1]= 13;
x[7][1]= 15;
//
y[0][0]= 12;
y[1][0]= 10;
y[2][0]= 8;
y[3][0]= 6;
y[4][0]= 4;
y[5][0]= 2;
y[6][0]= 21;
y[7][0]= 23;
//
y[0][1]= 11;
y[1][1]= 9;
y[2][1]= 7;
y[3][1]= 5;
y[4][1]= 3;
y[5][1]= 1;
y[6][1]= 22;
y[7][1]= 24;
//
z[0][0]= 13;
z[1][0]= 14;
z[2][0]= 5;
z[3][0]= 6;
z[4][0]= 17;
z[5][0]= 18;
z[6][0]= 21;
z[7][0]= 22;
//
z[0][1]= 15;
z[1][1]= 16;
z[2][1]= 7;
z[3][1]= 8;
z[4][1]= 19;
z[5][1]= 20;
z[6][1]= 23;
z[7][1]= 24;
int ans=0;
//check x
if(check(x,2)) ans=1;
if(check(x,-2)) ans=1;
if(check(y,2)) ans=1;
if(check(y,-2)) ans=1;
if(check(z,2)) ans=1;
if(check(z,-2)) ans=1;
if(ans==1) cout<<"YES";
else cout<<"NO";
return 0;
}
