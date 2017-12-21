#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<ll> vi;
const ll mod=int(1e9)+7;
int n,k;
int memo[500005];
ll dp(int i,int res){
    //add value to existing partition
    if(res!=k+1){
        res=fun();
    }
    //create new partition
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    vi a(n);
    memset(memo,0,sizeof(memo));
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<dp(0,0)<<endl;
    return 0;
}