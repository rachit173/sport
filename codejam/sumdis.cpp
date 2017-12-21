#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s0[4];
        string s1[4];
        for(int i=0;i<4;i++)
            cin>>s0[i];
        for(int i=0;i<4;i++)
        cin>>s1[i];        
        int c=0;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++)
                {
                    if(s0[i].compare(s1[j])==0){
                        c++;
                        break;
                    }
                }
            }
            if(c>=2)
                cout<<"similar"<<endl;
                else
                cout<<"dissimilar"<<endl;
        }
    return 0;
}