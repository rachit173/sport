#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    int D,I;
    while(T--){
        cin>>D>>I;
        int ans=1;
        I--;
        D--;
        while(D--){
            ans=(ans<<1)+I%2;
            I=I>>1;
        }
        cout<<ans<<endl;
    }
    int waste;
    cin>>waste; 
    return 0;
}