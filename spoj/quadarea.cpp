//created by rachit tibrewal 
//a good problem on convex optimisation
//Involves use of derivative use epsilon delta version of 
//differentiation
#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d",a)
#define sc1(a) scanf("%ld",&a)
#define pf1(a) printf("%ld",a)
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
#define ld long double
#define oo 1000000000
#define swap(a,b) {ld lol=a;a=b;b=lol;}
#define err 0.0000001
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ld eps=0.000001;
ld area(ld a,ld b,ld c){
    ld s,ret;
    s=(a+b+c)/2.0;
    ret=sqrtl((s*(s-a)*(s-b)*(s-c)));
    return ret;
}
ld der(ld a,ld b,ld c,ld d,ld e){
    return (area(a,b,c+eps)+area(d,e,c+eps)-area(a,b,c-eps)-area(d,e,c-eps));
}
ld fun(vector<ld> &a){
    int n=a.size();
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    ld mn=max(a[1]-a[0],a[3]-a[2]);
    ld mx=min(a[1]+a[0],a[2]+a[3]);
    ///if(mx<mn) return 0;
   // if(mx==mn) return area(a[0],a[1],mx)+area(a[2],a[3],mx);
    mx=mx-err;
    mn=mn+err;
    //cout<<mn<<" "<<mx<<endl;
    ld mid=(mn+mx)/2;
    //cout<<mid<<endl;
    ld tmp;
    for(int i=0;i<100;i++){
     //   cout<<mid<<" ";
        mid=(mn+mx)/2;
        tmp=der(a[0],a[1],mid,a[2],a[3]);
       // cout<<mid<<" "<<tmp<<" , ";
        if(tmp>0){
            mn=mid;
        }
        else mx=mid;
    }
    return area(a[0],a[1],mid)+area(a[2],a[3],mid);
}
int main(){
    int T;
    cin>>T;
    //cout<<area(3,3,3)<<endl;
    while(T--){
    vector<ld> a(4);
    f(i,4) cin>>a[i];
    sort(a.begin(),a.end());
    //a[0] and a[1] are adjacent
    ld ans1=fun(a);
    swap(a[1],a[2]);
    ld ans2=fun(a);
    printf("%.2Lf\n",max(ans2,ans1));
        } 
return 0;
}
