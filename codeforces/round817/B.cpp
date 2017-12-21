#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
int main(){
    int N;
    cin>>N;
    vi a(N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
        sort(a.begin(),a.end());
    int b[3];
    for(int i=0;i<3;i++)
    b[i]=a[i];
    if(a[0]==a[1]&&a[1]==a[2]){
        ll n=count(a.begin(),a.end(),a[0]);
        cout<<(n*(n-1)*(n-2))/6<<endl;
    }
    else if(a[0]==a[1]){
        ll n=count(a.begin(),a.end(),a[0]);
        ll t=count(a.begin(),a.end(),a[2]);
        cout<<((n*(n-1))/2)*(t)<<endl;
    }
    else if(a[1]==a[2]){
        ll n=count(a.begin(),a.end(),a[1]);
        ll t=count(a.begin(),a.end(),a[0]);
        cout<<((n*(n-1))/2)*(t)<<endl;
    }
    else{
        ll t1=count(a.begin(),a.end(),a[0]);
        ll t2=count(a.begin(),a.end(),a[1]);
        ll t3=count(a.begin(),a.end(),a[2]);
        cout<<t1*t2*t3<<endl;
    }
    return 0;
}