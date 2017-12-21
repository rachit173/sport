#include<bits/stdc++.h>


using namespace std;
#define ll long long int
typedef pair<ll,ll> ii;
typedef pair<int ,double> id;
typedef vector<id> vid;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef pair<double,int> di;
typedef vector<di> vdi;
int N;
ll graph[105][105];
double tim[105][105];
void tree(ll speed,ll dist,int source,int start,int end){
  if(graph[start][end]==-1)
    return;
  double claim=((graph[start][end]*1.0)/speed)+tim[source][start];
  if(claim<tim[source][end]&&dist>=graph[start][end]){
    tim[source][end]=claim;
    for(int i=0;i<N;i++){
      if(end==i||end==source)continue;
    tree(speed,dist-graph[start][end],source,end,i);
    }
  }
  else return;
}
int main(){
  int T;
  cin>>T;
  for(int t_i=0;t_i<T;t_i++)
  {
    printf("Case #%d: ",t_i+1);
  int Q;
  cin>>N>>Q;
  vii horse;
  memset(graph,-1,sizeof(graph));
  for(int i=0;i<N;i++){
    ll tmp,dis;
    scanf("%lld %lld",&dis,&tmp);
    horse.push_back(ii(dis,tmp));
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      scanf("%lld",&graph[i][j]);
  }
  //preprocessing
  for(int i=0;i<N;i++)
  for(int j=0;j<N;j++)
  tim[i][j]=10000005;
  for(int i=0;i<N;i++){
    tim[i][i]=0;
    ll speed=horse[i].second;
    ll dist=horse[i].first;
    for(int j=0;j<N;j++){
      tree(speed,dist,i,i,j);
    }
  }
  vector<vdi> AdjList;
  AdjList.assign(N,vdi());
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(tim[i][j]<10000000)
        AdjList[i].push_back(id(j,tim[i][j]));
    }
  }
  int a,b;
  cin>>a>>b;
  printf("%lf\n",tim[a][b]);
  continue;
  while(Q--){
  int s;
  int end;
  cin>>s>>end;
  vd dist(N,DBL_MAX);dist[s]=0;
  priority_queue< di,vector<di>,greater<di> >pq;
  pq.push(di(0,s));
  while(!pq.empty()){
    di front=pq.top();pq.pop();
    double d=front.first;
    int u=front.second;
    if(d>dist[u])continue;
    for(int j=0;j<(int)AdjList[u].size();j++){
      id v=AdjList[u][j];
      if(dist[u]+v.second<dist[v.first]){
        dist[v.first]=dist[u]+v.second;
        pq.push(di(dist[v.first],v.first));
      }
    }
  }
  printf("%f",dist[end]);
  }
  printf("\n");
  }
  return 0;
}
