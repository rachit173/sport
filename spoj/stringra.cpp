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
#define oo 1000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n,m;
int ans[100005];
int a[100005][2];
vi AdjList[100005];
vi AL[100005];
bool fun(){
    int v;
    RESET(ans,0);
    RESET(a,0);
    ans[0]=0;
    int k;
    int u;
    {
        k=1;
        for(int j=0;j<AdjList[0].size();j++){
            ans[AdjList[0][j]]=k;
          //  cout<<AdjList[0][j]<<" "<<k<<endl;
            // a[k]++;
            k++;
        }
    }
    int sz,tmp;
    for(int i=1;i<=n;i++){
        sz=AL[i].size();
        if((AL[i][sz-1]-AL[i][0]+1)!=sz) return false;
        if(ans[i]>0) continue;
        u=AL[i][0];
        tmp=ans[u];
        for(int j=u+1;j<=n;j++){
            if(tmp==ans[j]) return false;
        }
        ans[i]=tmp;
        
    }
    return true;
}
int main(){
int T;
cin>>T;
while(T--){
   // cout<<T<<endl;
    cin>>n>>m;
    int u,v;
    f(i,100005) AdjList[i].clear();
    f(i,100005) AL[i].clear();
    set<ii> myset;
    int opt=0;
    for(int i=0;i<m;i++){
        sc(u); sc(v);
                myset.insert(ii(u,v));
    }
    vii ed;
    copy(myset.begin(),myset.end(),back_inserter(ed));
    if(ed.size()!=m) {
        cout<<"-1"<<endl;
        continue;
    }
    for(int i=0;i<ed.size();i++){
        u=ed[i].ff;
        v=ed[i].ss;
        opt+=(u>=v);
        AdjList[u].pb(v);
        AL[v].pb(u);
        
    }
    if(opt>0){cout<<"-1"<<endl; continue;}
       for(int i=1;i<=n;i++) {sort(AdjList[i].begin(),AdjList[i].end());
       sort(AL[i].begin(),AL[i].end());}
    if(fun()==false){
        cout<<"-1"<<endl;
        continue;
    }
    // map<int,int> mp;
    // map<int,int> ::iterator it;
    // int k=1;

    // for(int i=1;i<=n;i++){
    //     it=mp.find(ans[i]);
    //     if(it==mp.end()){
    //         mp[(ans[i])]=k;
    //         k++;
    //     }
    // }
    for(int i=1;i<=n;i++) cout<<(ans[i])<<" ";
    cout<<endl;
}
return 0;
}
