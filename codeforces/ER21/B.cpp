#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i]; 
    ll avgsum=0;
    ll movingavgsum=0;
    for(int i=0;i<k;i++){
        movingavgsum+=a[i];
    }
    avgsum=movingavgsum;
    for(int i=k;i<n;i++){
        movingavgsum+=(a[i]-a[i-k]);
        avgsum+=(movingavgsum);
    }
    printf("%lf\n",avgsum*1.0/(n-k+1));
    return 0;
}