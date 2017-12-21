//rachit_
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dist(ll a,ll b){
    int t;
    t=a;
    ll da=0;
    while(t>0){
        da++;
        t=t/2;
    }
        t=b;
    ll db=0;
    while(t>0){
        db++;
        t=t/2;
    }
    if(a>b){
        a=a>>(da-db);
    }
    else{
        b=b>>(db-da);
    }
    ll k=0;
    while(a!=b){
        k++;
        a=a/2;
        b=b/2;
    }
    return 2*k+abs(da-db);
}
int main(){
    int T;
    cin>>T;
    ll p,q,r;
    while(T--){
        cin>>p>>q>>r;  
        if(dist(p,q)<dist(p,r))
        cout<<"FIRST"<<endl;
        else if(dist(p,q)==dist(p,r))
        cout<<"BOTH"<<endl;
        else
        cout<<"SECOND"<<endl;  
        }
    
    return 0;
}