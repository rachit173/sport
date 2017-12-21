#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long int
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(){
  string x,y;
  cin>>x>>y;
  bool exist=true;
  for(int i=0;i<x.size();i++)
  {
    if(y[i]>x[i]){
      exist=false;
      break;
    }
    else
      x[i]=y[i];
  }
  if(exist==true)
    cout<<x<<endl;
    else
      cout<<"-1"<<endl;
  return 0;
}
