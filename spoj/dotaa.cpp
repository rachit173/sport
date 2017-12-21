#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T--){
  int n,m,d;
  cin>>n>>m>>d;
  int t=0;
  int x;
  for(int i=0;i<n;i++) 
    {
      scanf("%d",&x);
      if(x%d==0) t+=((x/d)-1);
      else t+=(x/d);
    }
  if(t>=m) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  }
  return 0;

}
