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
typedef pair<char,int> ci;
typedef vector<ii> vii;
int main(){
int n;
cin>>n;
vector<ci> a(n);
f(i,n){
    scanf("\n%c %d",&a[i].ff,&a[i].ss);
}
int b[10];
int c[10];
int x = 0;
for(int i=0;i<n;i++){
    if(a[i].ff=='&') x = x&a[i].ss;
    if(a[i].ff=='^') x = x^a[i].ss;
    if(a[i].ff=='|') x = x|a[i].ss;
}
for(int i=0;i<10;i++){
    b[i] = x%2;
    x = x/2;
}
x = (1<<10)-1;
for(int i=0;i<n;i++){
    if(a[i].ff=='&') x = x&a[i].ss;
    if(a[i].ff=='^') x = x^a[i].ss;
    if(a[i].ff=='|') x = x|a[i].ss;
}
for(int i=0;i<10;i++){
    c[i] = x%2;
    x = x/2;
}
int p,q,r;
p=q=r=0;
for(int i=0;i<10;i++){
    if(b[i]==0&&c[i]==1){
        r = r|(1<<i);
    }
    else if(b[i]==0&&c[i]==0){
        continue;     
    }
    else if(b[i]==1&&c[i]==1){
        q = q|(1<<i);
        r = r|(1<<i);
    }
    else{
        p = p|(1<<i);
        r = r|(1<<i);
    }
}
pf(3);br;
printf("^ %d\n",p);
printf("| %d\n",q);
printf("& %d\n",r);
return 0;
}
