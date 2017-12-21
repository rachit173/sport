#include<bits/stdc++.h>
using namespace std;
bool check(int dx,int dy,int a,int b){
    if(dx%a!=0||dy%b!=0)
    return false;
    int t1=abs(dx/a)%2;
    int t2=abs(dy/b)%2;
    if(t1^t2==0)
    return true;
    return false;
}
int main(){
    int x1,y1,x2,y2;
    int x,y;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    if(check(x2-x1,y2-y1,x,y))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}