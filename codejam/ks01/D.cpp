#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
    int T;
    cin>>T;
    ll N,A,B,C1,C2,M,L1,R1;
    for(int t_i=0;t_i<T;t_i++){
        cin>>N>>L1>>R1>>A>>B>>C1>>C2>>M;
        ll x[N],y[N];
        vii a(N);
        x[0]=L1; y[0]=R1;
        a[0]=ii(x[0],y[0]);
        for(int i=1;i<N;i++)
        {
            x[i]=(A*x[i-1]+B*y[i-1]+C1)%M;
            y[i]=(A*y[i-1]+B*x[i-1]+C2)%M;
            a[i]=ii(min(x[i],y[i]),max(x[i],y[i]));
        }
        //brute force approach 
        //check the range without using a particular range
        stack<ii> s;
        sort(a.begin(),a.end());
        // for(int i=0;i<N;i++)
        // cout<<a[i].first<<" "<<a[i].second<<",";
        // cout<<endl;
        s.push(a[0]);
        int t1,t2,profit,max_profit;
        max_profit=0;
        ii top;
        t1=a[0].first;
        profit=0;
        for(int i=1;i<N;i++){
            top=s.top();
            if(top.second<a[i].first){
                profit+=top.second>=t1?(top.second-t1+1):0;
                t1=max(a[i].first,t1);
                //cout<<profit<<endl;
                max_profit=max(profit,max_profit);
                profit=0;
                s.push(a[i]);
            }
            else if(top.second<a[i].second){
                profit+=a[i].first>=t1?(a[i].first-t1):0;
                t1=max(top.second+1,t1);
                //cout<<profit<<endl;
                max_profit=max(profit,max_profit);
                profit=0;
                top.second=a[i].second;
                s.pop(); s.push(top);
            }
            else{
                if(t1<a[i].first) profit+=(a[i].first-t1);
                t1=max(a[i].second+1,t1);
            }
        }
        top=s.top();
        profit+=top.second>=t1?(top.second-t1+1):0;
        //cout<<profit<<endl;
        max_profit=max(max_profit,profit);
        int ans=0;
        while(!s.empty()){
            top=s.top();
            ans+=top.second-top.first+1;
            s.pop();
        }
        ans-=max_profit;
        cout<<"Case #"<<t_i+1<<": "<<ans<<endl;
    }
}