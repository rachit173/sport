#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
ll b[19];
ll iep(int d,int a[]){

}
int main(){
    int T;
    cin>>T;
    b[0]=1;
    for(ll i=1;i<19;i++){
        b[i]=b[i-1]*i;
    }
    while(T--){
    int a[10];
    ll L,R;
    ll ans=0;
    scanf("%lld %lld",&L,&R);
    for(int i=0;i<10;i++)
    scanf("%d",&a[i]);
    ll x=1;
    
}