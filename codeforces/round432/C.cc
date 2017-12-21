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
typedef struct p{
    int a[5];
}p;
int x[1005][1005];
int dis(p x,p y){
    int ret=0;
    f(i,5) ret+=((x.a[i]-y.a[i])*(x.a[i]-y.a[i]));
    return ret;
}
int main(){
    int n;
    sc(n);
    p arr[n];
    //srand(time(NULL));
    f(i,n){
        f(j,5) sc(arr[i].a[j]);
    }
    f(i,n){
        for(int j=i+1;j<n;j++){
            x[i][j]=x[j][i]=dis(arr[i],arr[j]);
        }
    }
    int u,v;
    bool s[1005];
    f(i,1005) s[i]=true;
//     for(int j=0;j<3;j++){
//     for(int i=0;i<n;i++){
//         u = (rand()+13)%n; v = rand() %n;
//         if((u==i)||(i==v)||(v==u)) continue;
//         if(x[u][v]<x[u][i]+x[v][i]) s[i] = false;
//         if(x[i][v]<x[i][u]+x[v][u]) s[u] = false;
//         if(x[u][i]<x[u][v]+x[i][v]) s[v] = false;    
//     }
// }
    int N=n;
    // f(i,n) if(s[i]==true) N++;
    // p arr1[N];
    // int k=0;
    // vi ind;
    // f(i,n){
    //     if(s[i]==true){ arr1[k++]=arr[i]; ind.pb(i);}
    // }
    // f(i,N){
    //     for(int j=i+1;j<N;j++){
    //         x[i][j]=dis(arr1[i],arr1[j]);
    //     }
    // }
    f(i,n) s[i]=true;
    // f(i,n){
    //     f(j,n) cout<<x[i][j]<<" ";
    //     cout<<endl;
    // }
    f(i,n){
        if(s[i]==false) continue;
        for(int j=i+1;j<n;j++){
            //if(i==j) continue;
            for(int k=j+1;k<n;k++){
                //if(j==k) continue;
//
                cout<<i<<" "<<j<<" "<<k<<endl;
                if(x[j][k]<(x[j][i]+x[k][i])) s[i] = false;
                if(x[i][k]<(x[i][j]+x[k][j])) s[j] = false;
                if(x[i][j]<(x[i][k]+x[j][k])) s[k] = false; 
            }
        }
    }
    vi ans;
    for(int i=0;i<n;i++){
        if(s[i]==true) {ans.pb(i);}
    }
    sort(ans.begin(),ans.end());
    pf((int)ans.size());br;
    for(int i=0;i<ans.size();i++) {pf(ans[i]+1);br;}   
return 0;
}
