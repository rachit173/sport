#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll sieve[1000000];
ll memo[1000005];
vii fact;
int k=2;
void print(){
    for(int i=0;i<fact.size();i++)
        cout<<fact[i].first<<": "<<fact[i].second<<endl;
}
bool cmp(ii a,ii b){
    return a.second<b.second;
}
bool isprime(int n){
    for(int i=0;sieve[i]<sqrt(n)+1&&sieve[i]!=0;i++){
        if(n%sieve[i]==0)
        return false;
    }
    return true;
}
ll prod(){
    ll ans=1;
    for(int i=0;i<fact.size();i++)
    ans*=(fact[i].second+1);
    return ans;
}
ll dp(ll n){
    if(n==1)
    return 0;
    if(fact.size()==0)
    {
        return 2;
    }
    if(n<1000000){
    if(memo[n]!=-1)
    return memo[n];
    }
    if(n<1000000){
        vii::iterator it=fact.end();
        it--;
        //print(fact);
        ll tmp=prod();
        //cout<<tmp<<endl;
        (*it).second-=1;
        ll p=(*it).first;
        //print(fact);
        //exit(0);
        sort(fact.begin(),fact.end(),cmp);
        memo[n]=tmp+dp((n/p));
        return memo[n];
    }
    else{
        vii::iterator it=fact.end();
        it--;
        ll tmp=prod();
        
        (*it).second-=1;
        ll p=(*it).first;
        sort(fact.begin(),fact.end(),cmp);
        return tmp+dp(n/p);
    }
}
ll driver(ll i){
        ll tmp=i;
        int j=0;
        int u=0;
        while(tmp>1&&j<k-1){
            if((tmp%sieve[j])==0){
                fact.push_back(ii(sieve[j],0));
            while((tmp%sieve[j])==0){
                tmp=tmp/(sieve[j]);
                fact[u].second++;
            }
            u++;
            }
            j++;
        }
        if(tmp>1)
        fact.push_back(ii(tmp,1));
        //cout<<i<<" : ";print();
        sort(fact.begin(),fact.end(),cmp);
        //exit(0);
        return dp(i);
}
int main(){
    ll a,b;
    memset(sieve,0,sizeof(sieve));
    memset(memo,-1,sizeof(memo));
    //generating primes
    sieve[0]=2;
    sieve[1]=3;
    for(int i=4;i<1000005;i++)
    {
        if(isprime(i)){
            sieve[k]=i;
            k++;
        }
    }
    scanf("%lld %lld",&a,&b);
    ll ans=0;
    ll i=a;
    while(i<=b){
        fact.clear();
        ans+=driver(i);
        i++;
    }
    printf("%lld\n",ans);
    return 0;
    }
    

    