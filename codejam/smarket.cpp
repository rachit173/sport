#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector <int> vi;
int main(){
int T;
scanf("%d",&T);
while(T--){
    int n,q;
    scanf("%d %d",&n,&q);
    int t,p;
    int start_index=0;
    int tmpcount=0;
    vi marker;
    vi len;
    //bitset <n> v;
    //v[0]=1
    scanf("%d",&p);
    tmpcount++;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&t);
        if(t==p){
            //v[i]=v[i-1];
            tmpcount++;
        }
        else{
            marker.push_back(start_index);
            len.push_back(tmpcount);
            start_index=i;
            tmpcount=1;
            //v[i]=v[i-1]^1;
            p=t;
        }
    }
    marker.push_back(start_index);
    len.push_back(tmpcount);
    //preprocessing  
    for(int i=0;i<marker.size();i++)
    cout<<marker[i]<<" ";
    //query answering
    int k,l,r;
    for(int x=0;x<q;x++){
        scanf("%d %d %d",&l,&r,&k);
        int count=0;
        l--;r--;
        vi::iterator low=lower_bound(marker.begin(),marker.end(),l);
        vi::iterator high=upper_bound(marker.begin(),marker.end(),r);
        int lowpos=low-marker.begin();
        int highpos=high-marker.begin();
        cout<<lowpos<<" "<<highpos<<endl;
        if(highpos==lowpos+1){
            if(r-l+1>=k)
            count++;
            printf("%d\n",count);
            continue;
        }
        if((marker[lowpos+1]-l)>=k)
        count++;
        if((r-marker[highpos-1]+1)>=k)
        count++;
        if(highpos!=lowpos+2){
        for(int i=lowpos+1;i<highpos;i++){
            if(len[i]>k)count++;
        }
        }
        printf("%d\n",count);
    }
}
return 0;
}