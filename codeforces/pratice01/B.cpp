#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void fun(int t,int s){
        int x=ceil(s*1.0/t);
    int a=s-t*(x-1);
    for(int i=0;i<a;i++)
    cout<<x<<" ";
    for(int i=a;i<t;i++)
    cout<<x-1<<" ";
}
int main(){
    int n,k,l,r,sall,sk;
    cin>>n>>k>>l>>r>>sall>>sk;
    int s=sall-sk;
    int t=n-k;
    //lower part 
    fun(t,s); 
    //upper part
    fun(k,sk);
    return 0;
}