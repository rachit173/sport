#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    int arr[]={20,20,19,18,10,9,10,11,14,15};
    vi a(arr,arr+10);
    sort(a.begin(),a.end());
    vi::iterator low,up;
    up=upper_bound(a.begin(),a.end(),15);
    cout<<"The upper bound is at "<<up-a.begin()<<" and the value is "<<*up<<endl;
    return 0;
}
//sorted array 9,10,10,11,14,15,18,19,20,20
               