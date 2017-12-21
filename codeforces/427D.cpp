#include<bits/stdc++.h>
#include<un
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
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod1 1000000009
#define mod2 1000000007
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n;
int a[6000];
char s[6000];
ll h1[6000];
ll h2[6000];
int fun(int l,int r){

}
int main(){
    
    cin>>s;
    n=strlen(s);
    a[0]=0;
    h1[0]=((s[0]-'a')*mod1)%mod1;
    h2[0]=((s[0]-'a')*mod2)%mod2;
    int x=mod1,y=mod2;
    for(int i=0;i<n;i++){__STDC_FORMAT_MACROS
    }
    for(int i=1;i<n;i++){
        if(i>=n-i-1)
        a[i]=fun(0,i-1);
        else
        a[i]=fun(i-(n-i-1),i-1);
    }
return 0;
}
