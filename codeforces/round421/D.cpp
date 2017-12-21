#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define ll long long int
int main(){
    ll dev=ll(1e13);
    int n;
    ll a[n];
    ll s[2*n];
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[n+i]=a[i];
    }
    s[0]=abs(a[0]-1);
    for(int i=0;i<n;i++)
        s[i]+=s[i-1]+abs(a[i]-i+1);
    return 0;
}