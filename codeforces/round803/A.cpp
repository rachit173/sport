#include<bits/stdc++.h>
using namespace std;
typedef vector<int > vi;
typedef pair<int ,int  > ii;
typedef vector<ii> vii;
int main(){
  int n,k;
  cin>>n>>k;
  int a[n][n];
  memset(a,0,sizeof(a));
  if(k>n*n){
    printf("-1\n");
  return 0;}
  if(k==n*n){
    memset(a,1,sizeof(a));

  }
  for(int i=n,j=0;i>0;i--,j++){
    if(k>=(2*i-1)){
      for(int x=j;x<n;x++){
        a[j][x]=1;
        a[x][j]=1;
      }
      k-=(2*i-1);
    }
    else if(k==0)
      break;
    else{
      if(k%2==0){
      a[j+1][j+1]=1;
      k--;
      }
      int t=(k+1)/2;
      for(int x=j;x<j+t;x++){
        a[j][x]=1;
        a[x][j]=1;
      }
      break;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      printf("%d ",a[i][j]);
      printf("\n");

    }
  return 0;
}
