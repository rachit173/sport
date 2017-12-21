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
vi AL[10001];
int memo[10001];
int prime[10001];
void convert(int a[4],int x){
    for(int i=0;i<4;i++) {
        a[i]=x%10;
        x=x/10;
    }
    return ;
}
int deconvert(int b[4]){
    int ret=0;
    for(int i=3;i>=0;i--){
        ret = ret*10+b[i];
    }
    return ret;
}

int main(){
    RESET(prime,0);
    prime[1]=0;
for(int i=2;i<10000;i++){
    if(prime[i]) continue;
    for(int j=2*i;j<10000;j+=i) prime[j]=1;
}
// for(int i=1;i<10000;i++){
//     if(prime[i]==0) {pf(i);br;}
// }
//create the graph
int t;
for(int u=1000;u<10000;u++){
    int a[4];
    convert(a,u);
    int b[4];
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    b[3]=a[3];
    // pf(b[0]);pf(b[1]);
    // pf(b[2]);pf(b[3]);
    for(int j=0;j<4;j++){
        b[0]=a[0];
        b[1]=a[1];
        b[2]=a[2];
        b[3]=a[3];
    for(int i=0;i<10;i++){
            if(i!=a[j]){
                b[j]=i;
                t = deconvert(b);
                // pf(t);
                // int foo;sc(foo);
                if(prime[t]==0&&b[3]!=0) AL[u].pb(t); 
            }
        }
    }

}
int T;
cin>>T;
int x,y;
set<int> st;
while(T--){
    sc(x);
    sc(y);
    // if(!prime[x]&&!prime[y]) printf("both prime\n");
    RESET(memo,0);
    queue<ii> q;
    q.push(ii(x,0));
    memo[x]=1;
    int ans=-1;
    while(ans==-1&&!q.empty()){
        ii tmp = q.front();
        // pf(tmp.ff);sp;pf(tmp.ss);br;
        q.pop();
        t = tmp.ff;
        if(t==y){
            ans = tmp.ss;
            break;
        }
        for(int i=0;i<AL[t].size();i++){
            if(memo[AL[t][i]]==0){
                memo[AL[t][i]]=1;
                q.push(ii(AL[t][i],tmp.ss+1));
            }
        }
    }
    if(ans==-1){
        printf("Impossible\n");
    }
    else
    printf("%d\n",ans);
}
return 0;
}
