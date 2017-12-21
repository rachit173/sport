#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<ll> vi;
int main(){
    //preprocessing
    vi a(20000);
    int i=0;
    a[i++]=1;
    int j=6;
    while(i<20000){
        a[i]=(a[i-1]+j); j+=6; i++;
    }
    ll q;
    while(1){
        cin>>q;
        if(q==-1) break;
        if(binary_search(a.begin(),a.end(),q)) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}