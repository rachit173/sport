#include<bits/stdc++.h>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define  ll long long int
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
priority_queue < ii ,vector<ii>,greater<ii> > pq;
int res[10000000];
int gcd(int a, int b)
{

    if (a == 0)
        return b;
    if(a==b)
    return a;
    return gcd(b%a, a);
}
ll fun(ll a,ll b){
    return a*b/(gcd(a,b));
}
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        int B,N;
        cin>>B>>N;
        //clear the queue
        while(!pq.empty())
        pq.pop();    
        vector<int> v(B);
        for(int i=0;i<B;i++)
        scanf("%d",&v[i]);
                if(B==1){
        printf("Case #%d: %d\n",t_i+1,1);
        continue;
        }
        //find the lcm
        int lcm=fun(v[0],v[1]);
        for(int i=2;i<B;i++){
            lcm=fun(lcm,v[i]);
        }
        //simulation till the lcm
        ll no_people_round=0;
        for(int i=0;i<B;i++)
        no_people_round+=(lcm/v[i]);
        N--;
        N=N%no_people_round;

        for(int i=0;i<B;i++){
            pq.push(ii(0,i));
        }
        ii cur;
        int ans;
        for(int i=0;i<=N;i++)
        {
            cur=pq.top();
            pq.pop();
            ans=cur.second;
            pq.push(ii(cur.first+v[cur.second],cur.second));
        }
        printf("Case #%d: %d\n",t_i+1,ans+1);
    }
    return 0;
}