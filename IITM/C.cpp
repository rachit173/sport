#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
bool genprime(int n,vi &prime){
    for(int i=0;i<prime.size()&&prime[i]<=(sqrt(n)+1);i++){
        if(n%prime[i]==0)return false;
    }
    return true;
}
ll instab(int n,vi &prime){
    int tmp=n;
    ll ret=1;
    ll x;
    ll y;
    if(n==1)
    return 1;
    for(int i=0;i<prime.size()&&tmp>1;i++){
        x=1;
        y=1;
        while(tmp%prime[i]==0){
            tmp=tmp/prime[i];
            x=x*prime[i];
            y+=x;
        }
        ret*=y;
    }
    if(tmp==n)
    return n+1;
    return ret;
}
int main(){
    ll A,B;
    cin>>A>>B;
    vi prime;
    prime.push_back(2);
    //cout<<genprime(3,prime);
    for(int i=3;i<10000;i++)
        if(genprime(i,prime)==true) prime.push_back(i);
    
    ll ans=0;
    for(int i=A;i<=B;i++){
        ll x=i;
        ans+=abs(2*x-instab(i,prime));
    }
    cout<<ans<<endl;
    return 0;
}