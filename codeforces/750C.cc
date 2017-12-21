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
int a[300000][2];
int n;
int check(int st,int x){
    for(int i=st;i<n;i++){
        if(a[i][1]==1){
            if(x<1900) return -oo;
            x+=a[i][0];
        }
        else{
            if(x>=1900) return -oo;
            x+=a[i][0];
        }
    }
    return x;
}
// int recheck(int en,int x) {
//     for(int i=en;i>0;i--){
//         if(a[i][1]==1){
//             if(x<1900) return -oo;
//             x-=a[i-1][0];
//         }
//         else{
//             if(x>=1900) return -oo;
//             x-=a[i-1][0];
//         }
//     }
//     return x;
// }
int main(){
cin>>n;
int opt1=0;
int opt2=0;

f(i,n){
    sc(a[i][0]);
    sc(a[i][1]);
    if(a[i][1]==2) opt1=1;
    if(a[i][1]==1) opt2=1;
}
    int b[n];
    b[0] = a[0][0];
    f1(i,1,n) b[i] = b[i-1]+a[i][0];
if(opt1==0){
    printf("Infinity\n");
}
else if(opt2==0){
    int mx=0;
    // int mn=0;
    f(i,n-1){
        // mn = min(mn,b[i]);
        mx = max(mx,b[i]);
    }
    int tmp = 1899-mx;
    pf(tmp+b[n-1]);br;
}
else {
    int j;
    f(i,n-1){
        if(a[i][1]!=a[i+1][1]){j=i;break;}
    }
    int haha=0;
    if(j>0){
        haha = b[j-1];
    }
    if(a[j][1]==1){
            int tmp = 1899-a[j][0];
            // cout<<"1"<<" "<<tmp<<echeckndl;
            vi arr;
            while(tmp>=1900){
                arr.pb(check(0,tmp-haha));
                tmp--;
            }
            int mx=-oo;
            if(arr.size()<1){ printf("Impossible\n"); return 0;}
            else{
                mx = arr[0];
                f(i,arr.size()) mx = max(mx,arr[i]);
            }
            if(mx==-oo) printf("Impossible\n");
            else {
                pf(mx);br;
            }
    }
    else{

        int tmp = 1900-a[j][0];
        // cout<<"2"<<" "<<tmp<<endl;
        vi arr;
            while(tmp<1900){
                arr.pb(check(0,tmp-haha));
                tmp++;
            }
            int mx=-oo;
            if(arr.size()<1){ printf("Impossible\n"); return 0;}
            else{
                mx = arr[0];
                f(i,arr.size()) mx = max(mx,arr[i]);
            }
            if(mx==-oo) printf("Impossible\n");
            else {
                pf(mx);br;
            }
    }
}
return 0;
}
