#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    int days=1;
    int p=v0;
    int cap=v0+a;
    int tmp1,tmp2;
    while(p<c){
        tmp1=min(p,l);
        tmp2=min(cap-tmp1,v1-tmp1);
        p+=tmp2;
        days++;
        cap+=a;
    }
    cout<<days<<endl;
    return 0;
}