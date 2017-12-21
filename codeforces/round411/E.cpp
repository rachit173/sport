#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vi> AdjList;
  AdjList.assign(n,vi);
  int t;
  int tmp;
  for(int i=0;i<n;i++)
  {
  cin>>t;
  for(int j=0;j<t;j++)
  {
    scanf("%d",&tmp);
  AdjList[i].push_back(tmp);
  }
  }

  return 0;
}
