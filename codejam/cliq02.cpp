#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long int
typedef pair<ll,ll> ii; //pair of int;pair<int,int>
typedef vector<ll> vi; //vector of int
typedef vector<ii> vii; //vector of pair<int,int>
#define INF 10000000000000000
int main() {
    //number of testcases
    int TC;
    cin>>TC;  
    while(TC--){
      //vertices,edges,source
        int V,E,K,X,M,s=0,u,v,w;
        //the graph is stored as an adjacency list with tuples of int,int as unit storage
        vector<vii> AdjList;
     scanf("%d %d %d %d %d",&V,&K,&X,&M,&s);
        //initialising the adjacency list with empty vector
        AdjList.assign(V,vii());
        //using 0-index
        s--;
        /*for(int i=0;i<K;i++){
            for(int j=i+1;j<K;j++){
                AdjList[i].push_back(ii(j,X));
                AdjList[j].push_back(ii(i,X));
            }
        }*/
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&u,&v,&w);
            AdjList[u-1].push_back(ii(v-1,w));
            AdjList[v-1].push_back(ii(u-1,w));
        }
        //source or root of the sspt tree
        //vector<int> to store the minimum distance from source
        vi dist(V,INF);dist[s]=0;
        //priority queue to store the possible candidates of the next vertice to be fixed with the minimum distance
        //initialised with 
        priority_queue< ii,vector<ii>,greater<ii> > pq;
        pq.push(ii(0,s));
        while(!pq.empty()){
            ii front =pq.top();pq.pop();
            ll d=front.first,u=front.second;
            if(d>dist[u]) continue;
            for(int j=0;j<(int)AdjList[u].size();j++){
                ii v=AdjList[u][j];
                if(dist[u]+v.second<dist[v.first]){
                    dist[v.first]=dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
        int con=0;
        int mndist=dist[0];
        //cout<<dist[0]<<" ";
        for(int i=1;i<K;i++)
        {
            //cout<<dist[i]<<" ";
            if(dist[i]<mndist){
                mndist=dist[i];
                con=i;
            }
        }
        //connnecting the vertices of the complete part to the graph to the mindist vertice and now applying djikstra
        for(int i=0;i<K;i++){
            if(i!=con){
                AdjList[i].push_back(ii(con,X));
                AdjList[con].push_back(ii(i,X));
            }
        }
                dist.assign(V,INF);dist[s]=0;
        //priority queue to store the possible candidates of the next vertice to be fixed with the minimum distance
        //initialised with 
        pq.push(ii(0,s));
        while(!pq.empty()){
            ii front =pq.top();pq.pop();
            ll d=front.first,u=front.second;
            if(d>dist[u]) continue;
            for(int j=0;j<(int)AdjList[u].size();j++){
                ii v=AdjList[u][j];
                if(dist[u]+v.second<dist[v.first]){
                    dist[v.first]=dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }

        for(int i=0;i<V;i++){
         printf("%lld ",dist[i]);   
        }
        printf("\n");
    }
    return 0;
}