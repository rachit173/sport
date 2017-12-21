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
typedef struct node{
    int x;
    int y;
    int z;
    int r;
    int l;
}node;
bool cmp(node& a,node& b){
    if(a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}
int main(){
int T;
cin>>T;
f(t_i,T){
    int N;
    cin>>N;
    node arr[N];
    int x[N],y[N],z[N];
    int R[N];
    int a[N],b[N],c[N],d[N],e[N];
    int a1[N],b1[N],c1[N],d1[N];
    f(i,N) cin>>arr[i].x>>arr[i].y>>arr[i].z>>arr[i].r;
    f(i,N){
        arr[i].l = arr[i].x+arr[i].r;
    }
    sort(arr,arr+N,cmp);
    int mn1=1000000000;
    f(i,N) mn1 = min(mn1,arr[0].x-arr[0].r);
    a[0] = arr[0].y+arr[0].r;
    b[0] = arr[0].y-arr[0].r;
    c[0] = arr[0].z+arr[0].r;
    d[0] = arr[0].z-arr[0].r;
    e[0] = max(a[0]-b[0],c[0]-d[0]);
    f1(i,1,N) {
        a[i] = max(arr[i].y+arr[i].r,a[i-1]);
        b[i] = min(arr[i].y-arr[i].r,b[i-1]);
        c[i] = max(arr[i].z+arr[i].r,c[i-1]);
        d[i] = min(arr[i].z-arr[i].r,d[i-1]);
        e[i] = max(a[i]-b[i],c[i]-d[i]);
    }
    int f[N];
    a1[N-1] = arr[N-1].y+arr[N-1].r;
    b1[N-1] = arr[N-1].y-arr[N-1].r;
    c1[N-1] = arr[N-1].z+arr[N-1].r;
    d1[N-1] = arr[N-1].z-arr[N-1].r;
    f[N-1] = max(a1[N-1]-b1[N-1],c1[N-1]-d1[N-1]);
    for(int i=N-2;i>=0;i--){
        a1[i] = max(arr[i].y+arr[i].r,a1[i+1]);
        b1[i] = min(arr[i].y-arr[i].r,b1[i+1]);
        c1[i] = max(arr[i].z+arr[i].r,c1[i+1]);
        d1[i] = min(arr[i].z-arr[i].r,d1[i+1]);
        f[i] = max(a1[i]-b1[i],c1[i]-d1[i]);
    }
    int ans=1000000000;
    for(int i=0;i<N-1;i++){
        // cout<<e[i]<<" "<<f[i]<<endl;
        ans = min(ans,max(e[i],max(f[i+1],max(arr[i].x+arr[i].r-mn1,arr[N-1].x+arr[N-1].r-arr[i+1].x+arr[i+1].r))));
    }
    f(i,N){
        int c=x[i];
        x[i]=y[i];
        y[i]=c;
    }
    f(i,N){
        arr[i].l = arr[i].x-arr[i].r;
    }
    sort(arr,arr+N,cmp);
        int mn2=1000000000;
    f(i,N) mn2 = min(mn2,arr[0].x-arr[0].r);
    a[0] = arr[0].y+arr[0].r;
    b[0] = arr[0].y-arr[0].r;
    c[0] = arr[0].z+arr[0].r;
    d[0] = arr[0].z-arr[0].r;
    e[0] = max(a[0]-b[0],c[0]-d[0]);
    f1(i,1,N) {
        a[i] = max(arr[i].y+arr[i].r,a[i-1]);
        b[i] = min(arr[i].y-arr[i].r,b[i-1]);
        c[i] = max(arr[i].z+arr[i].r,c[i-1]);
        d[i] = min(arr[i].z-arr[i].r,d[i-1]);
        e[i] = max(a[i]-b[i],c[i]-d[i]);
    }
    a1[N-1] = arr[N-1].y+arr[N-1].r;
    b1[N-1] = arr[N-1].y-arr[N-1].r;
    c1[N-1] = arr[N-1].z+arr[N-1].r;
    d1[N-1] = arr[N-1].z-arr[N-1].r;
    f[N-1] = max(a1[N-1]-b1[N-1],c1[N-1]-d1[N-1]);
    for(int i=N-2;i>=0;i--){
        a1[i] = max(arr[i].y+arr[i].r,a1[i+1]);
        b1[i] = min(arr[i].y-arr[i].r,b1[i+1]);
        c1[i] = max(arr[i].z+arr[i].r,c1[i+1]);
        d1[i] = min(arr[i].z-arr[i].r,d1[i+1]);
        f[i] = max(a1[i]-b1[i],c1[i]-d1[i]);
    }
    // int ans=1000000000;
    for(int i=0;i<N-1;i++){
        // cout<<e[i]<<" "<<f[i]<<endl;
        ans = min(ans,max(e[i],max(f[i+1],max(arr[i].x+arr[i].r-mn2,arr[N-1].x+arr[N-1].r-arr[i+1].x+arr[i+1].r))));
    }
    f(i,N){
        int c=x[i];
        x[i]=z[i];
        z[i]=c;
    }
    f(i,N){
        arr[i].l = arr[i].x-arr[i].r;
    }
    sort(arr,arr+N,cmp);
        int mn3=1000000000;
    f(i,N) mn3 = min(mn3,arr[0].x-arr[0].r);
    a[0] = arr[0].y+arr[0].r;
    b[0] = arr[0].y-arr[0].r;
    c[0] = arr[0].z+arr[0].r;
    d[0] = arr[0].z-arr[0].r;
    e[0] = max(a[0]-b[0],c[0]-d[0]);
    f1(i,1,N) {
        a[i] = max(arr[i].y+arr[i].r,a[i-1]);
        b[i] = min(arr[i].y-arr[i].r,b[i-1]);
        c[i] = max(arr[i].z+arr[i].r,c[i-1]);
        d[i] = min(arr[i].z-arr[i].r,d[i-1]);
        e[i] = max(a[i]-b[i],c[i]-d[i]);
    }
    a1[N-1] = arr[N-1].y+arr[N-1].r;
    b1[N-1] = arr[N-1].y-arr[N-1].r;
    c1[N-1] = arr[N-1].z+arr[N-1].r;
    d1[N-1] = arr[N-1].z-arr[N-1].r;
    f[N-1] = max(a1[N-1]-b1[N-1],c1[N-1]-d1[N-1]);
    for(int i=N-2;i>=0;i--){
        a1[i] = max(arr[i].y+arr[i].r,a1[i+1]);
        b1[i] = min(arr[i].y-arr[i].r,b1[i+1]);
        c1[i] = max(arr[i].z+arr[i].r,c1[i+1]);
        d1[i] = min(arr[i].z-arr[i].r,d1[i+1]);
        f[i] = max(a1[i]-b1[i],c1[i]-d1[i]);
    }
    // int ans=1000000000;
    for(int i=0;i<N-1;i++){
        // cout<<e[i]<<" "<<f[i]<<endl;
        ans = min(ans,max(e[i],max(f[i+1],max(arr[i].x+arr[i].r-mn3,arr[N-1].x+arr[N-1].r-arr[i+1].x+arr[i+1].r))));
    }
    // cout<<ans<<endl;
    printf("Case #%d: %d\n",t_i+1,ans);
}
return 0;
}
