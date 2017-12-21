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
ll a[12345][2][2];
ll memo[12345][2];
vi AL;
int n,m;
ll dp(int ind,int c){
    //cout<<n<<" "<<m<<" "<<ind<<" "<<c<<" "<<a[ind][c][0]<<" "<<a[ind][c][1]<<endl;
    if(ind<0||c<0) return 0;
    if(c==0&&ind>=n) return 0;
    if(c==1&&ind>=m) return 0;
    if(memo[ind][c]!=-1) return memo[ind][c];

    if(a[ind][c][1]!=-1) memo[ind][c] = max(a[ind][c][0]+dp(a[ind][c][1]+1,c^1),a[ind][c][0]+dp(ind+1,c));
    else memo[ind][c] = a[ind][c][0]+dp(ind+1,c);
    return memo[ind][c];
}
int main(){
    while(1){
        RESET(memo,-1);
        RESET(a,-1);
        sc(n);
        if(n==0) break;
        f(i,n) sc1(a[i][0][0]);
        sc(m);
        f(i,m) sc1(a[i][1][0]);
        int i=0;
        int j=0;
        while(i<n&&j<m){
            if(a[i][0][0]==a[j][1][0]) {
                a[i][0][1]=j;
                a[j][1][1]=i;
                i++;j++;
                continue;
            }
            else if(a[i][0][0]>a[j][1][0]) j++;
            else i++;
        }
    //    cout<<"he";
        pf1(max(dp(0,0),dp(0,1)));br;
    }
return 0;
}
