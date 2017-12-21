#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> vi;
void increase(vi & tmp,vi & c){
    for(int i=0;i<c.size();i++)
    tmp[i]+=c[i];
}
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        int N,P;
        cin>>N>>P;
        vector <int> c(N);
        vector <vi> a(N,vi(P));
        for(int i=0;i<N;i++)
        scanf("%d",&c[i]);
        for(int i=0;i<N;i++)
        for(int j=0;j<P;j++)
        scanf("%d",&a[i][j]);
        for(int i=0;i<N;i++)
        sort(a[i].begin(),a[i].end());
        vi marker(N,0);
        int count=0;
        int k=0;
        vi tmp(N,0);
        int opt=true;
        increase(tmp,c);
        while(opt){
            
            int *tp;
            int cost;
            for(int i=0;i<N;i++){
                tp=&marker[i];
                //cout<<(*tp)<<" ";
                cost=tmp[i];
                //cout<<cost<<" ";
                //cout<<a[i][(*tp)]<<" ";
                while(a[i][(*tp)]<0.9*cost&&(*tp)<P)(*tp)++;
            }
            bool check=true;
            for(int i=0;i<N;i++){
                tp=&marker[i];
                cost=tmp[i];
                if((*tp)==P){
                    check=false;
                    opt=false;
                    break;
                }
                if(a[i][(*tp)]>1.1*cost){
                check=false;break;}
            }
            if(check==false){
                increase(tmp,c);
            continue;
            }
            else
            {
                for(int i=0;i<N;i++)
                    marker[i]++;
                count++;
                
            }
        }
        printf("Case #%d: %d\n",t_i+1,count);
    }
    return 0;
}