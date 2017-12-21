#include<bits/stdc++.h>
using namespace std;
typedef vector<int > vi;
#define INF 10000000
int main(){
  int n;
  cin>>n;
  vi a(n);
  vi d(n,INF);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  int zero_pos=-2*INF;
  for(int i=0;i<n;i++){
    if(a[i]==0){
      zero_pos=i;
      d[i]=0;
    }
    else if(abs(i-zero_pos)<d[i])
      d[i]=abs(i-zero_pos);

  }
   zero_pos=-2*INF;
       for(int i=n-1;i>=0;i--){
             if(a[i]==0){
               zero_pos=i;
                d[i]=0;
              }
              else if(abs(i-zero_pos)<d[i])
                 d[i]=abs(i-zero_pos);
             
              }
  for(int i=0;i<n;i++)
    printf("%d ",d[i]);
  return 0;
}
