#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sc1(a) scanf("%lld",&a);
#define pf1(a) printf("%lld",a);
#define sc2(a) scanf("%d %d",&a.first,&a.second);
#define br printf("\n");
#define sp printf(" ");
#define ll long long int
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
int main(){
int n,a,b;
cin>>n>>a>>b;
if(n<2){
    pf(0);br;return 0;
}
ii arr[n];
f(i,n) sc2(arr[i]);
int ans=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
       // cout<<arr[i].ff<<" "<<arr[i].ss<<" "<<arr[j].ff<<" "<<arr[j].ss<<endl;
        if((arr[i].ff+arr[j].ff<=a)&&max(arr[i].ss,arr[j].ss)<=b){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
        if((arr[i].ss+arr[j].ss<=b)&&max(arr[i].ff,arr[j].ff)<=a){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
        int tmp=arr[i].ss;
        arr[i].ss=arr[i].ff;
        arr[i].ff=tmp;
                if((arr[i].ff+arr[j].ff<=a)&&max(arr[i].ss,arr[j].ss)<=b){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
        if((arr[i].ss+arr[j].ss<=b)&&max(arr[i].ff,arr[j].ff)<=a){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
                tmp=arr[j].ss;
        arr[j].ss=arr[j].ff;
        arr[j].ff=tmp;
            if((arr[i].ff+arr[j].ff<=a)&&max(arr[i].ss,arr[j].ss)<=b){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
        if((arr[i].ss+arr[j].ss<=b)&&max(arr[i].ff,arr[j].ff)<=a){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
                tmp=arr[i].ss;
        arr[i].ss=arr[i].ff;
        arr[i].ff=tmp;
                    if((arr[i].ff+arr[j].ff<=a)&&max(arr[i].ss,arr[j].ss)<=b){
            ans=max(ans,arr[i].ff*arr[i].ss+arr[j].ff*arr[j].ss);
        }
        if((arr[i].ss+arr[j].ss<=b)&&max(arr[i].ff,arr[j].ff)<=a){
            ans=max(ans,arr[i].ff*arr[ i].ss+arr[j].ff*arr[j].ss);
        }
    }
}
cout<<ans<<endl;
return 0;
}
