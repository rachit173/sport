#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int V;
int graph[100][100];
int lol[100][100];
void dfs(int start,int dominator){
  for(int i=0;i<V;i++){
    if(graph[start][i]==1&&lol[i][dominator]==0){
      lol[i][dominator]=1;
      dfs(i,dominator);
    }
  }
}
int main(){
  int E;
  cin>>V>>E;
  //int graph[V][V];
  memset(graph,0,sizeof(graph));
  int u,v;
  for(int i=0;i<E;i++){
    cin>>u>>v;
    graph[u][v]=1;
  }
  memset(lol,0,sizeof(lol));
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++)
      graph[i][j]*=-1;
    dfs(0,i);
    for(int j=0;j<V;j++)
      graph[i][j]*=-1;
  }
  for(int i=0;i<V;i++)
    {
      cout<<i<<" : ";
      //sort(lol[i].begin(),lol[i].end);
      for(int j=0;j<V;j++)
        if(lol[i][j]==0) cout<<j<<" ";
      cout<<"\n";
    }

return 0;
}
