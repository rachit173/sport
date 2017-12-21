#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long int
int main(){
  int T;
  cin>>T;
  set<int> first;
  while(T>0){
  int n,t;
  first.clear();
  set<int>::iterator it;
  //set<int>::iterator beg=first.begin();
  ll count=0;
  cin>>n;
  cin>>t;
  first.insert(t);
  for(int i=1;i<n;i++)
  {
    scanf("%d",&t);
    first.insert(t);
    it=first.find(t);
    count+=(distance(it,first.end())-1);
  }
  cout<<count<<endl;
  T--;
  }
  return 0;
}
