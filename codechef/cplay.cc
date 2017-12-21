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
char s[50];
void check(){
    int a=0,b=0;
    f(i,5){
        if(a>b+(5-i)){
            printf("TEAM-A %d\n",2*i); return ;
        }
        a+=(s[2*i]-'0');
        if(a>b+(5-i)){
            printf("TEAM-A %d\n",2*i+1); return ;
        }
        if(b>a+(4-i)){
            printf("TEAM-B %d\n",2*i+1); return ;
        } 
         b+=(s[2*i+1]-'0');
         if(b>a+(4-i)){
            printf("TEAM-B %d\n",2*i+2); return ;
        } 
        }
    if(a>b){
        printf("TEAM-A 10\n"); return ;
    }
    else if(b>a){
        printf("TEAM-B 10\n"); return ;
    }
    else {
        a=0;b=0;
        f(i,5){
            a+=(s[10+2*i]-'0');
            b+=(s[10+2*i+1]-'0');
            if(a>b){
                printf("TEAM-A %d\n",10+2*i+2); return ;
            }
            else if(b>a){
                printf("TEAM-B %d\n",10+2*i+2); return ;
            }
        }
        printf("TIE\n"); return ;
    }
}
int main(){
while(scanf("%s",s)==1){
    check();
}
return 0;
}
