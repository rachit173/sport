
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> ii; //pair of int;pair<int,int>
typedef vector<int> vi; //vector of int
typedef vector<ii> vii; //vector of pair<int,int>
#define INF 1000000000
int main() {
    //number of testcases
    int TC;
    cin>>TC;  
    while(TC--){
      //vertices,edges,source
        int V,E,s=0,u,v,w;
        //the graph is stored as an adjacency list with tuples of int,int as unit storage
        vector<vii> AdjList;
     scanf("%d %d",&V,&E);
        //initialising the adjacency list with empty vector
        AdjList.assign(V,vii());
        //using 0-index
        for(int i=0;i<E;i++){
            scanf("%d %d %d",&u,&v,&w);
            AdjList[u-1].push_back(ii(v-1,w));
            AdjList[v-1].push_back(ii(u-1,w));
        }
        //source or root of the sspt tree
        scanf("%d",&s);
        s--;
        //vector<int> to store the minimum distance from source
        vi dist(V,INF);dist[s]=0;
        //priority queue to store the possible candidates of the next vertice to be fixed with the minimum distance
        //initialised with 
        priority_queue< ii,vector<ii>,greater<ii> > pq;
        pq.push(ii(0,s));
        while(!pq.empty()){
            ii front =pq.top();pq.pop();
            int d=front.first,u=front.second;
            if(d>dist[u])continue;
            for(int j=0;j<(int)AdjList[u].size();j++){
                ii v=AdjList[u][j];
                if(dist[u]+v.second<dist[v.first]){
                    dist[v.first]=dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
        for(int i=0;i<V;i++){
          if(s==i)
            continue;
         if(dist[i]==INF) printf("-1 ");   
         else printf("%d ",dist[i]);   
        }
        printf("\n");
    }
    return 0;
}

