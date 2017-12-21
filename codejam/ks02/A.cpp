#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define ll long long int
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int s=0;
    int q;
    //vi v(b,0);
    int ans=0;
    int t;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<b;i++) pq.push(0);
    while(n--){
        cin>>q;
        if(!pq.empty())
        t=pq.top();
        else 
        t=-1;
        if(q==1){
            
            if(s<a) s++;
            else if(t==0||t==1){
                pq.pop();pq.push(t+1);
            }
            else ans++;
        }
        else{
            if(t==0){
                pq.pop();
            }
            else ans+=2;
        }
    }
    cout<<ans;
    return 0;
}