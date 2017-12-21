#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
template <class T1, class T2> struct pair;
typedef pair<int,int> pr;
bool cmp(pr i,pr j){
  return i.first<j.first;
}
int main(){
  int myints[]={10,20,20,30,10,23,24,10,20,30,40};
  vector <pr> v(8);
  for(int i=0;i<11;i++){
    v[0]=make_pair(myints[i],i);
  }
  sort(v.begin(),v.end());
  pair <vector <pr>::iterator,vector <pr>::iterator> bounds;
  bounds=equal_range(v.begin(),v.end(),20,cmp);
  cout<<(bounds.first-v.begin())<<" "<<(bounds.second-v.begin())<<endl;
  return 0;
}
