#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    int Y,N;
    while(scanf("%d",&Y)==1)
    {
        cin>>N;
        vi a(N);
        for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
        vi cfa(N);
        cfa[0]=a[0];
        int up,ans=0;
        vi::iterator up_it;
        int yr1,yr2;
        for(int i=0;i<N;i++){
            up=a[i]+Y-1;
            up_it=upper_bound(a.begin(),a.end(),up);
            if((int)(up_it-a.begin())-i>ans){
                ans=(int)(up_it-a.begin())-i;
                yr1=a[i];
                yr2=a[i+ans-1];
            }
        }
        cout<<ans<<" "<<yr1<<" "<<yr2<<endl;
    }
    return 0;
}