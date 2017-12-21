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
vii AL;
bool make(int x){
   int b[10];
   
}
int main(){
int n;
cin>>n;
int t;
int a[3][6];
f(i,n){
    f(j,6){
        sc(a[i][j]);
    }
}
set<int> s;
s.clear();
if(n>=1){
    for(int i=0;i<n;i++) for(int j=0;j<6;j++) s.insert(a[i][j]);
}
if(n>=2){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[0][i]*10+a[1][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[1][i]*10+a[0][j]));
    }
}
if(n>=3){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[0][i]*10+a[1][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[1][i]*10+a[0][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[1][i]*10+a[2][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[2][i]*10+a[1][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[2][i]*10+a[0][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++) s.insert((a[0][i]*10+a[2][j]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++)
            for(int k=0;k<6;k++) s.insert((a[2][i]*100+a[1][j]*10+a[0][k]));
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++)
            for(int k=0;k<6;k++) s.insert(a[2][i]*100+a[0][j]*10+a[1][k]);
            }
    for(int i=0;i<6;i++){
            for(int j=0;j<6;j++)
                for(int k=0;k<6;k++) s.insert(a[1][i]*100+a[2][j]*10+a[0][k]);
        }
    for(int i=0;i<6;i++){
            for(int j=0;j<6;j++)
                for(int k=0;k<6;k++) s.insert(a[1][i]*100+a[0][j]*10+a[2][k]);
                }
    for(int i=0;i<6;i++){
                for(int j=0;j<6;j++)
                    for(int k=0;k<6;k++) s.insert(a[0][i]*100+a[1][j]*10+a[2][k]);
            }
    for(int i=0;i<6;i++){
                for(int j=0;j<6;j++)
                    for(int k=0;k<6;k++) s.insert(a[0][i]*100+a[2][j]*10+a[1][k]);
    }
}
        // for(set<int>::iterator it=s.begin();it!=s.end();it++)
        // {pf(*it);sp;}
    vi arr(s.begin(),s.end());
    // for(int i=0;i<arr.size();i++) pf(arr[i]);
    int i=0;
    int j=0;
    if(arr[0]==0) j++;
    while(j<arr.size()){
        if(arr[j]==i+1) {i++;j++;}
        else break;
    }
    cout<<i<<endl;
return 0;
}
