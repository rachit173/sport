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
#define MAXN 500005
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int a[MAXN];
vi g[MAXN];
int tour[MAXN];
int bnum[MAXN];
int h[MAXN];
int ht[MAXN];
int haha=0;
ll seg1[MAXN];
//segment tree for Range Maximum Query 
void update1(int index,int l,int r,int val,int base){
    if(r<=l){
        seg1[base] =val;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update1(index,l,mid-1,val,2*base);
        seg1[base] = min(seg1[2*base],seg1[2*base+1]);
        // cout<<index<<" "<<l<<" "<<r<<" "<<base<<" "<<seg1[base]<<endl;
    }else{
        update1(index,mid,r,val,2*base+1);
        seg1[base] = min(seg1[2*base],seg1[2*base+1]);
        // cout<<index<<" "<<l<<" "<<r<<" "<<base<<" "<<seg1[base]<<endl;
    }
}
ll search1(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg1[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search1(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search1(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg1[base];
    return min(search1(start,mid-1,l,mid-1,2*base),
                search1(mid,end,mid,r,2*base+1));
}
void dfs(int x,int pr){
    h[x] = haha;
    tour[haha++]  = x;
    int cnt=0;
    for(int i=0;i<(int)g[x].size();i++){
        if(g[x][i]!=pr){
            cnt++;
            dfs(g[x][i],x);
            tour[haha++] = x;
        }
    }
}
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
int n;
sc(n);
f(i,n+2) g[i].clear();
int x,y;
// int arr[n+2];
f(i,3*n) seg1[i]=0;

// RESET(arr,-1);
int x,y;
f(i,n-1){
    sc(x);sc(y);
    g[x].pb(y);
    g[y].pb(x);
}
int root=1;
// for(int i=1;i<=n;i++){
//     if(arr[i]==-1){
//         root=i;
//         break;
//     }
// }
int kw=1;
queue<ii> q;
q.push(ii(1,-1));
while(!q.empty()){
    ii t = q.front();
    q.pop();
    bnum[kw++] = t.ff;
    for(int i=0;i<(int)g[t.ff].size();i++){
        if(g[t.ff][i]!=t.ss){
            q.push(ii(g[t.ff][i],t.ff));
        }
    }
}
//euler tour of tree 
dfs(root,-1);
int N=haha;
for(int i=0;i<N;i++){
    // pf(tour[i]);sp;
    update1(i,0,N-1,tour[i],1);
}
br;
int Q;
sc(Q);
printf("Case %d:\n",t_i+1);
while(Q--){
    int u,v;
    sc(u); sc(v);
    if(h[u]<h[v]){
        pf(bnum[search1(h[u],h[v],0,N-1,1)]);br;
    }
    else {
        pf(bnum[search1(h[v],h[u],0,N-1,1)]);br;
    }
}
    }
return 0;
}
