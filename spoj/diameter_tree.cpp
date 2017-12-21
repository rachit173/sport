//this solution has passed the tests on spoj online judge 
//the solution can be used as a ready function to find the diameter of a rooted or unrooted tree
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int strandlen[10001];
int m=0;
vector <vi> AdjList;
int strands(int node,int parent){
  if(strandlen[node]!=-1)
  return strandlen[node];
  strandlen[node]=0;
  for(int i=0;i<(int)AdjList[node].size();i++){
    if(AdjList[node][i]!=parent){
      strandlen[node]=max(strandlen[node],strands(AdjList[node][i],node)+1);
    }
  }
  return strandlen[node];
}
int diameter(int node,int parent){
  //self chord
  int m=0;
  vi a;
  int t;
  for(int i=0;i<(int)AdjList[node].size();i++){
    t=AdjList[node][i];
    if(t!=parent)
    a.push_back(strandlen[t]+1);
  }
  if(a.size()>1){
    nth_element(a.begin(),a.begin()+1,a.end(),greater<int>());
    m=a[0]+a[1];
  }
  else if(a.size()==1){
    m=a[0];
  }
  for(int i=0;i<(int)AdjList[node].size();i++){
    t=AdjList[node][i];
    if(t!=parent)
    m=max(m,diameter(t,node));
  }
  return m;
}
int main(){
  int n,u,v;
  cin>>n;
  AdjList.assign(n,vi());
  memset(strandlen,-1,sizeof(strandlen));
  for(int i=0;i<n-1;i++){
    scanf("%d %d",&u,&v);
    AdjList[u-1].push_back(v-1);
    AdjList[v-1].push_back(u-1);
  }
srand(time(NULL));
int s=rand()%n;
//cout<<s<<endl;
int use=strands(s,s);
//for(int i=0;i<n;i++ )
//cout<<strandlen[i]<<" ";
//cout<<endl;
int ans=diameter(s,-1);
cout<<ans<<endl;
  return 0;
}
