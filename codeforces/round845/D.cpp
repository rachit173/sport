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
#define oo 100000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
    int n;
    cin>>n;
    int t,s;
    vii eve(n);
    f(i,n){
        sc(t);
        if(t==1||t==3) sc(s);
        eve[i]=ii(t,s);
    }
    bool spd=true;
    int v=oo;
    int currspeed;
    int ans=0;
    int a[n];
    // f(i,n){
    //     switch(eve[i].ff){
    //     case 1:
    //         currspeed=eve[i].ss;
    //         if(currspeed>v){ 
    //             if(spd==false){
    //                 ans++;
    //                 spd=true;
    //             }
    //         }
    //         break; 
    //     case 2:
    //         break;
    //     case 3:
            
    //         spd=false;
    //         if(currspeed>v){ 
    //             ans++;
    //             spd=true;
    //         }else{
    //             v=eve[i].ss;
    //         }
    //         break;
    //     case 4:
    //         break;
    //     case 5:
    //         v=oo;
    //         spd=true;
    //         break;
    //     case 6:
    //         break;
    // }
    // }
    int foo=0;
    f(i,n){
        if(eve[i].ff==3||eve[i].ff==5) a[i]=foo;
        else if(eve[i].ff==1) foo=eve[i].ss;
    }
    int overtakes=0;
    fr(i,n){
        switch(eve[i].ff){
            case 2:
                overtakes++;
                break;
            case 4:
                overtakes=0;
                break;
            case 6:
                if(overtakes>0) ans++;
                break;
            default:
                break;
        }
    }
    int speed=0;
    int maxspeed=0;
    fr(i,n){
        switch(eve[i].ff){
            case 1:
                speed=eve[i].ss;
                maxspeed=max(speed,maxspeed);
                break;
            case 3:
                maxspeed=max(a[i],maxspeed);
                if(maxspeed>=eve[i].ss) ans++;
                speed=a[i];
                break;
            case 5:
                speed=a[i];
                maxspeed=speed;
                break;
            default:
                break;

        }
    }
    cout<<ans<<endl;
return 0;
}
