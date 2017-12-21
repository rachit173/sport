#include<bits/stdc++.h>
using namespace std;
double fun(int n){
    double ret=0;
    for(int i=1;i<=n;i++)
    ret+=log10(i);
    return ret;
}
int main(){
    double p[5];
    for(int i=0;i<5;i++)
    cin>>p[i];
    double ps=1-(p[0]+p[1]+p[2]+p[3]+p[4]);
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<"log10(0)\n";
        return 0;
    }
    //cout<<fun(n);
    double ans=1;
    if(n-k>50){
        cout<<"log10(0)\n";
    }
    else if(k==0){
        cout<<floor(n*1.0*log10(ps))<<endl;
    }    
    else{
        if(n==k)
        ans=fun(n)-fun(k)+k*1.0*log10(1-ps);
        else
        ans=fun(n)-fun(k)-fun(n-k)+(n-k)*1.0*log10(ps)+k*1.0*log10(1-ps);
        cout<<floor(ans)<<endl;
    }
    return 0;
}