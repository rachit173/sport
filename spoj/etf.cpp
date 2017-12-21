#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//int memo[1000006];
int totient(int N){
  //if(memo[N]!=-1) return memo[N];
int tmp=N;
int ans=N;
for(int i=2;i<1001&&tmp>1;i++){
  if(tmp%i==0){
    ans=(ans/i)*(i-1);
    while(tmp%i==0) tmp/=i;
  }
}
 if(tmp>1) return (ans/tmp)*(tmp-1);
 return ans;
}
int main(){
  int T;
  cin>>T;
  //memset(memo,-1,sizeof(memo));
  //memo[1]=1;
  //memo[0]=1;
  int N;
  while(T--){
  cin>>N;
  if(N==1) {cout<<1<<endl;
    continue;
  }
  cout<<totient(N)<<endl;
  }
return 0;
}
