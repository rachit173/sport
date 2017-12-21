#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1000000007;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<int,int> vii;
ll memo2[100005];
ll memo[100005];
int n;
ll a[100005];
ll dp(int i,ll base){
    if(i==n-1)
    return (a[n-1]*base)%mod;
    if(memo[i]!=-1&&base==1){
        return memo[i];
    }
    else if(base>1){
        return ((((base*a[i])%mod)*memo2[n-i-2])%mod+dp(i+1,1)+dp(i+1,(a[i]*base)%mod))%mod;
    }
    else{
            memo[i]=(((a[i]*memo2[n-i-2])%mod+dp(i+1,1))+dp(i+1,a[i]))%mod;
    return memo[i];
    }

}
int main(){
    int T;
    cin>>T;
    memo2[0]=1;
    for(int i=1;i<100005;i++){
        memo2[i]=(memo2[i-1]*2)%mod;
    }
    //cout<<memo2[10]<<" "<<memo2[2]<<endl;
    while(T--){
    cin>>n;
    memset(memo,-1,sizeof(memo));
    
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    cout<<dp(0,1)<<endl;
    }
    return 0;
}