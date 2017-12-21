#include<bits/stdc++.h>
using namespace std;
double pi=atan(1)*4;
double mul;
int main(){
    int n;
    double a;
    cin>>n>>a;
    //ii t;
    double mn=181;
    mul=(360.00)/n;
    int tmp;
    // for(int i=1;i<n-1;i++){
    //     tmp=bin(i+1,n-1);
    //     if(abs(calc(i,tmp)-a)<mn){
    //         t=ii(i,tmp);
    //         mn=abs(calc(i,tmp)-a);
    //     }
    // }
    int ans;
    //cout<<mul;
    for(int i=1;i<n-1;i++){
        if(abs(mul*i*0.5-a)<mn){
            ans=i;
            mn=abs(mul*i*0.5-a);
        }
    }
    cout<<"2 1 "<<ans+2<<endl;
    return 0;
}