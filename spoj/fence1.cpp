#include<bits/stdc++.h>
using namespace std;
int main(){
  double pi=4*atan(1.0);
  int l;
  cin>>l;
  while(l!=0){
    printf("%.2lf\n",(double)(l*l)/2/pi);


    cin>>l;
  }
  return 0;
}
