//basic TC passed
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
bool bigger(ii a,ii b)
{
  return a.first*b.second>b.first*a.second;
}
void binsearch(ii left,ii right,ii in,ii root){
    if(root==in) return;
    if(bigger(in,root))
    {
      cout<<"R";
      left=root;
      root.first+=right.first;
      root.second+=right.second;
    }
    else{
      cout<<"L";
      right=root;
      root.first+=left.first;
      root.second+=left.second;
    }
    binsearch(left,right,in,root);
}
int main(){
  ii in;
  while(1)
  {
    scanf("%d %d",&in.first,&in.second);
    if(in.first==1&&in.second==1) break;
    string s;
    ii root=make_pair(1,1);
      binsearch(make_pair(0,1),make_pair(1,0),in,root);
    cout<<endl;
  }
    return 0;
}