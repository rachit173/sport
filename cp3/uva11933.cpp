#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define setOn(S,j) S|(1<<j)
#define isOn(S,j) S==(S|(1<<j))
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)
        break;
        int a=0,b=0;
        int opt=0;
        for(int i=0;i<31;i++){
            if(isOn(n,i)){
                if(opt==0)
                a=setOn(a,i);
                else
                b=setOn(b,i);
                opt=opt^1;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}