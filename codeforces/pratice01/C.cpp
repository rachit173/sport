#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49,51};
    string y="yes";
    string n="no";
    string s;
    int div=0;
    for(int i=0;i<20;i++){
        cout<<a[i]<<endl; fflush(stdout);
        cin>>s;fflush(stdout);
        if(s==y) div++;
    }
    if(div<2)
    cout<<"prime";
    else
    cout<<"composite";
    return 0;
}