#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include <queue>
const long long int INF=233333333333; 
using namespace std;
int g[3005][3005];
bool v[3005];
long long int md[3005];
int mindist(int n){
    long long int mn=INF;
    int min_index;
    for(int i=0;i<n;i++){
        if(!v[i]&&md[i]<mn){
            min_index=i;
            mn=md[i];
            }
    }
    return min_index;
}
void dijkstra(int n){
    
    for(int count=0;count<n;count++){
        int u=mindist(n);
        v[u]=true;
        for(int y=0;y<n;y++){
            if(v[y]==false&&g[u][y]&&(md[u]+g[u][y])<md[y])
                md[y]=md[u]+g[u][y];
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int TC;
    cin>>TC;
    while(TC--){
        memset(g,0,sizeof(g));
        memset(v,false,sizeof(v));
        for(int i=0;i<3005;i++)
            md[i]=INF;
        int n,m;
        cin>>n>>m;
        int source=0;
        int x,y,d;
        for(int i=0;i<m;i++){
            cin>>x>>y>>d;
            g[x-1][y-1]=g[y-1][x-1]=d;
        }
        md[0]=0;
        dijkstra(n);
        for(int i=1;i<n;i++){
            if(md[i]==INF)
                cout<<"-1"<<" ";
            else
                cout<<md[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

