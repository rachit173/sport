#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int,int> ii;
typedef vector<int > vi;
typedef vector<ii> vii;
int main(){
  int l,r;
  cin>>l>>r;
  int a[10]={0};
  a[0]=0;
  a[1]=1;
  int count=0;
  for(int i=2;i<10;i++){
    count=0;
    if(l%i==0)
      count++;
     if(r%i==0)
       count++;
    count+=(r-l)/i;
    if(l%i==0&&r%i==0)
      count--;
     a[i]=count;

  }
  int m=0;
  int num=2;
  for(int i=2;i<10;i++){
    if(a[i]>m){m=a[i];num=i;}
  }
  if(l!=r){
  printf("%d",num);
  }
  else
    printf("%d",l);
  return 0;
}
