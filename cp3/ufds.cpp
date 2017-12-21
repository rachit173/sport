#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<cstring>
#define vi vector <int>
using namespace std;
class UnionFind {
  private:
    vi p,rank;
  public:
    UnionFind(int N){
      rank.assign(N,0);
      p.assign(N,0);
      for(int i=0;i<N;i++)p[i]=i;
    }
    int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i]));}
    bool isSameSet(int i,int j){return (findSet(i)==findSet(j));}
    void unionSet(int i,int j){
      if(!isSameSet(i,j)){
        int x=findSet(i),y=findSet(j);
        if(rank[x]>rank[y])p[y]=p[x];
        else{ p[x]=p[y];
        if(rank[x]==rank[y])rank[y]++;
        }
      }
    }
    void print(){
      for(vector <int>::iterator it=p.begin();it!=p.end();++it)
        printf("%d ",*it);
      printf("\n");
    }
};
int main(){
  int t;
  cin>>t;
  for(int t_i=0;t_i<t;t_i++)
  {
    int N;
    cin>>N;
    UnionFind f(N);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
      int x,y;
      cin>>x>>y;
      f.unionSet(x,y);  
    }
    f.print();
  }
  return 0;
}
    


