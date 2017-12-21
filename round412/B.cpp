#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<int,int> vii;
bool check(int p,int s){
  vi a(25);
  int i=(s/50)%475;
  for(int j=0;j<25;j++)
  {
    i=(i*96+42)%475;
    a[j]=26+i;
  }
  for(int j=0;j<25;j++)
  {
    if(p==a[j])
      return true;
  }
  return false;
}
int main()
{
  int p,x,y;
  cin>>p>>x>>y;
  int hacks=1;
  int t=x;
  int hack2=0;
  while(y<=t&&check(p,t)!=true){
    t-=50;
  }
  if(y>x)
  {
    hacks=ceil((y-x)*1.0/100); 
  }
  while(check(p,x+hacks*100)!=true&&check(p,x+hacks*100-50)!=true){
    hacks++;
  }
  int ans;
  ans=hacks;
  if(check(p,t)==true){
    ans=0;
  }
  cout<<ans<<endl;
  return 0;
}
