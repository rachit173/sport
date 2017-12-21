#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    int a,b;
    cin>>a>>b;
    int p1,p2;
    p1=sqrt(a);
    p2=-0.5+(float)sqrt(b*1.0+0.25);
    if(p1>p2)
        cout<<"Valera\n";
    else
        cout<<"Vladik\n";
    return 0;
}