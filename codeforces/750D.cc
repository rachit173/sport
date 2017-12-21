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
inline int sgn(int x_){
    if(x_>=0) return 1;
    return -1;
}
ii convert(int x,int y){
                    int x1,y1;
                if(abs(x)>=abs(y)){
                    x1 = sgn(x)*(abs(x)-abs(y));
                    y1 = x1;
                    int baba = sgn(x1);
                    y1+= sgn(y)*((1+sgn(y)*sgn(x))/2)*abs(y);
                    x1+= sgn(x)*((1-sgn(y)*sgn(x))/2)*abs(y);
                    return ii(x1,y1);
                }
                ii tmp = convert(-y,x);
                return ii(tmp.ss,-tmp.ff);
}
int main(){
int n;
cin>>n;
int a[n];
    f(i,n) cin>>a[i];
    set<ii> memo;
    ii tmp;
    int x,y;
    int Q;
    cin>>Q;
    while(Q--){
        sc2(tmp);
        tmp = convert(tmp.ff,tmp.ss);
        cout<<tmp.ff<<" "<<tmp.ss<<endl;
    }
    for(int i=n-1;i>=0;i--){
        set<ii> s1;
        s1.clear();
        f(j,a[i]) s1.insert(ii(0,j));
        if(i<n-1){
            for(auto e:memo){
                //tmp = (*e);
                x = (e).ff;
                y = (e).ss;

                // }
                // else{
                // }
                    tmp = convert(x,y);
                    int x1=tmp.ff;
                    int y1 = tmp.ss;
                s1.insert(ii(x1-1,y1+a[i]));
                s1.insert(ii(1-x1,y1+a[i]));
            }
        }
        memo.clear();
        memo = s1;
    }
    int grid[20][20];
    RESET(grid,0);
    for(auto e:memo){
        grid[-e.ss+10][e.ff+10]=1;
    }
    f(i,20){
        f(j,20) cout<<grid[i][j];
        cout<<endl;
    }
    // for(auto e:memo) cout<<e.ff<<" "<<e.ss<<endl;
    cout<<memo.size()<<endl;
return 0;
}
