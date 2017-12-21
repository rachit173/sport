#include<bits/stdc++.h>
using namespace std;

int main(){
    int TC;
    cin>>TC;
    for(int t_i=0;t_i<TC;t_i++){
        int N,L;
        scanf("%d %d",&N,&L);
        vector <string> os(N);
        vector <string> ds(N);
        for(int i=0;i<N;i++)
        cin>>os[i];
        for(int i=0;i<N;i++)
        cin>>ds[i];
        int counto[L]={0};
        int countd[L]={0};
        bool flip[L]={false};
        for(int i=0;i<N;i++){
            for(int j=0;j<L;j++){
                if(os[i][j]=='1')
                counto[j]++;
                if(ds[i][j]=='1')
                countd[j]++;
            }
        }
        int count=0;
        bool mid[L]={false};
        for(int i=0;i<L;i++){
            if(count[i]==count[d]&&count[i]==N/2)
                mid[i]=true;
            if(counto[i]!=countd[i]){
            flip[i]=true;
            count++;
            }
        }devices
        //for(int i=0;i<L;i++)
        //cout<<flip[i]<<" ";
        //cout<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<L;j++){
                if(flip[j]==true){
                    if(os[i][j]=='1')
                    os[i][j]='0';
                    else
                    os[i][j]='1';
                }
            }
        }
        // for(int i=0;i<N;i++){
          //  cout<<os[i]<<" ";                            
        //}
        sort(os.begin(),os.end());
        sort(ds.begin(),ds.end());
        bool same=true;
        for(int i=0;i<N;i++){
            if(os[i].compare(ds[i])!=0){
                same=false;
                break;
            }
        }
        if(same==true){
            printf("Case #%d: %d\n",t_i+1,count);
        }
        else{
            printf("Case #%d: NOT POSSIBLE\n",t_i+1);
        }
    }

    return 0;
}