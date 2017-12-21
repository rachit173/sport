#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
int main(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int i;
    for(i=1;i<n;i++)
    if(a[i]<=a[i-1]) break;
    i++;
    for(;i<n;i++)
        if(a[i]!=a[i-1]) break;
    for(i;i<n;i++)
        if(a[i]>=a[i-1]) break;
    if(i>=n){
         cout<<"YES\n";
    }
    else
    cout<<"NO\n";
    
}