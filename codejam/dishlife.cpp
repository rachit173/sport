#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        int isle[N]={0};
        int m[K]={0};
        int t;
        int k;
        for(int i=0;i<N;i++)
        {
            cin>>t;
            for(int j=0;j<t;j++){
                cin>>k;
                if(m[k-1]==0)isle[j]=1;
                m[k-1]++;
            }
        }
        int tmp=*min_element(m,m+K);
        if(tmp==0){
            cout<<"sad\n";
        }
        else if(tmp==1){
            if(!(*min_element(isle,isle+N)))
                cout<<"all\n";
                else
                cout<<"some\n";
        }
        else
            cout<<"some\n";
    }
    return 0;
}