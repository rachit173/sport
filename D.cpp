#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define oo 1000000009
#define first ff
#define second ss;
typedef vector<int> vi;
typedef pair<int,int> ii;
int main(){
    ll A,B;
    cin>>A>>B;
    ll t;
    ll ans=0;
    for(int i=1;i<=(int)A;i++){
        t=i;
        t=t*t+B;
        t=sqrt(t);
        ans+=t-i;
    }
    cout<<ans;
    return 0;
}