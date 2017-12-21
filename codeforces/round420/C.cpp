#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define ll long long int
int main(){
    int n;
    cin>>n;
    string s,a;
    a="add";
    int t;
    priority_queue<int,vector<int>,greater<int> > pq;
    int ans=0;
    int mn=1;
    bool r=false;
    for(int i=0;i<2*n;i++){
        cin>>s;
        if(s==a){
            cin>>t;
            if(!pq.empty()&&t>pq.top()&&pq.top()==mn){
                ans++; r=false; }
            else if(!pq.empty()&&t>pq.top()) r=true;
            pq.push(t);                
        }
        else {
                if(r==true)
                {
                    ans++; r=false;
                }
            mn=pq.top()+1; pq.pop();
            }
    }
    cout<<ans<<endl;
    return 0;
}