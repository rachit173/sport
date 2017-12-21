#include<bits/stdc++.h>
using namespace std;
int L[1000005],L1[1000000],L2[1000000],L3[1000000];
int main(){
  int N,K;
  cin>>N;
  for(int i=0;i<N;i++){ scanf("%d",&L[i]);
  L1[i]=L2[i]=L[i];
  }
  cin>>K;
  for(int i=0;i<N;i++)
  {
    if(i%K!=0) L1[i]=max(L1[i],L1[i-1]);
  }
  for(int i=N-2;i>=0;i--) if((i+1)%K!=0) L2[i]=max(L2[i],L2[i+1]);
  for(int i=0;i<N+1-K;i++) L3[i]=max(L2[i],L1[i+K-1]);
  for(int i=0;i<N+1-K;i++) printf("%d ",L3[i]);
  printf("\n");

return 0;
}
