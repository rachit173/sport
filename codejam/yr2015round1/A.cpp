#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
        ll y=0,z=0;
        //first method
        for(int i=0;i<N-1;i++){
            if(a[i+1]<a[i])
            y+=(ll)(a[i]-a[i+1]);
        }
        //second method
        int v=0;
        int max_dis=0;
        for(int i=0;i<N-1;i++){
            if(a[i]>=a[i+1]) max_dis=max(max_dis,a[i]-a[i+1]);
        }
        v=max_dis;
        for(int i=0;i<N-1;i++){
            z+=(ll)min(max_dis,a[i]);
        }
        printf("Case #%d: %lld %lld\n",t_i+1,y,z);
    }
}