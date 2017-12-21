#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
int main(){
    int n,k;
    cin>>n>>k;
    int ne=n-k;
    ne--;
    int mn=2;
    if(ne==0){
        cout<<"2"<<endl;
        for(int i=0;i<k;i++){
            cout<<"1"<<" "<<i+2<<endl;
        }
    }
    else if(ne==1){
        cout<<"3"<<endl;
        for(int i=0;i<ne;i++){
            cout<<i+1<<" "<<i+2<<endl;
        }
        if(ne>1)
        cout<<ne+1<<" "<<"1"<<endl;
        cout<<"2 "<<ne+2<<endl;
        for(int i=0;i<k-1;i++)
        cout<<"1 "<<ne+3+i<<endl;
    }
    else{
                cout<<"2"<<endl;
        for(int i=0;i<ne;i++){
            cout<<i+1<<" "<<i+2<<endl;
        }
        cout<<ne+1<<" "<<"1"<<endl;
       // cout<<"2 "<<ne+2<<endl;
        for(int i=0;i<k;i++)
        cout<<"1 "<<ne+2+i<<endl;
    }
    return 0;
}