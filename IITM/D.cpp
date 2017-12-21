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
// num --> given natural number
int divSum(int num)
{
    // Final result of summation of divisors
    int result = 0;
 
    // find all divisors which divides 'num'
    for (int i=2; i<=sqrt(num); i++)
    {
        // if 'i' is divisor of 'num'
        if (num%i==0)
        {
            // if both divisors are same then add
            // it only once else add both
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
 
    // Add 1 to the result as 1 is also a divisor
    return (result + 1);
}
int main(){
    ll A,B;
    cin>>A>>B;
    ll ans=0;
    for(int i=A;i<=B;i++){
        ans+=abs(i-divSum(i));
    }
    cout<<ans<<endl;
    return 0;
}