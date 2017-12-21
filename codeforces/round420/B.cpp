#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define ll long long int
int main(){
    int m,b;
    cin>>m>>b;
    ll x=m*b,y;
    ll mx=-1;
   // cout<<x<<" "<<m;
    for(int i=0;i<=b&&x>=0;i++){
        y=i;
        mx=max(mx,(x*y*(x+y+2))/2+(y*(y+1))/2+(x*(x+1))/2);
        x-=m;
    }
    cout<<mx<<endl;
    return 0;
}