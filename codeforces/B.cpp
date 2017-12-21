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
int main(){
    int n,k;
    cin>>n>>k;
    int t1=2*n;
    int t2=n;
    int a[k];
    for(int i=0;i<k;i++) sc(a[i]);
    //sort(a,a+n);
    //int b[k];
    int b[4]={0};
    f(i,k) {
        if(a[i]%4==3) {
            b[1]++;b[2]++;
            continue;
        }
        b[a[i]%4]++;
    }
//sort(b,b+n);
//cout<<b[0]<<b[1]<<b[2]<<b[3]<<endl;
    int c=0;
    f(i,k) c+=a[i]/4;
    //cout<<c<<endl;
    if(t1>=b[2]){
        t1=t1-b[2];
  //      cout<<t1<<b[1];
        if(t1>=b[1]){
            t1=t1-b[1];
            if(t1/2+t2>=c) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
    //        cout<<b[1];
            b[1]-=t1;
            t2=t2-ceil(b[1]/2.0);
            if(t2>=c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }else{
        b[2]=b[2]-t1;
        t2=t2-b[2];
        b[1]=b[1]-b[2];
        if(b[1]<=0){
            if(t2>=c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;                
        }else{
            t2=t2-ceil(b[1]/2.0);
            if(t2>=c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
return 0;
}
