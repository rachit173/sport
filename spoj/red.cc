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
typedef pair<int,string> is;
int n;
// int x1,y1;
int u,v;
is grid[300][300];
int aux[300][300];
is dp(int st,int en){
    // cout<<st<<" "<<en<<endl;
    // char foo;
    // cin>>foo;
    if(st==u&&en==v) return is(0,"");
    if(st<0||st>=n||en<0||en>=n) return is(oo,"");
    if(aux[st][en]==1) return is(oo,"");
    aux[st][en] = 1;
    if(grid[st][en].ff!=-1) return grid[st][en];
    is ret;
    is ans=is(oo,"");
    string s;
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //UL
    ret = dp(st-2,en-1);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "UL";
    }
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //UR
    ret = dp(st-2,en+1);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "UR";
    }
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //R
    ret = dp(st,en+2);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "R";
    }
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //LR
    ret = dp(st+2,en+1);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "LR";
    }
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //LL
    ret = dp(st+2,en-1);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "LL";
    }
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    //L
    ret = dp(st,en-2);
    if(ret.ff<ans.ff){
        ans = ret;
        s = "L";
    }
    // grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    aux[st][en]=0;
    grid[st][en] = is(ans.ff+1,s+" "+ans.ss);
    // return is(ans.ff+1,s+" "+ans.ss); 
    return grid[st][en];
}
int main(){
    // RESET(grid,-1);
    f(i,300){
        f(j,300) grid[i][j].ff=-1;
    }
    RESET(aux,0);
    cin>>n;
    int x,y;
    sc(x);
    sc(y);
    sc(u);
    sc(v);
    is ans = dp(x,y);
    if(ans.ff<10000){
        cout<<ans.ff<<endl;
        cout<<ans.ss<<endl;
    } 
    else{
        cout<<"Impossible"<<endl;
    }
return 0;
}
