#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",&a);
#define ll long long int
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii; 
int main(){
  int N;
  cin>>N;
  ll a[103];
  vi arr1(1000005);
  vi arr2(1000005);
  int sz1=0;
  int sz2=0;
  for(int i=0;i<N;i++) scanf("%lld",&a[i]);
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++) if(a[k]!=0) arr1[sz1++]=(a[i]+a[j])*a[k];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++) arr2[sz2++]=(a[i]*a[j])+a[k];
  sort(arr1.begin(),arr1.begin()+sz1);
  sort(arr2.begin(),arr2.begin()+sz2);
  //return 0;
//  for(int i=0;i<sz2;i++) cout<<arr2[i]<<" ";
  vii b(1000000);
  b[0]=ii(arr1[0],1);
  int k=0;
  for(int i=1;i<sz1;i++){
    if(arr1[i]==arr1[i-1]) b[k].second++;
    else{
      k++;
      b[k]=ii(arr1[i],1);
    }
  }
  //for(int i=0;i<k;i++) cout<<b[i].first<<" "<<b[i].second<<" ,";
  k++;
  int ans=0;
  int i=0,j=0;
  while(i<sz2&&j<k){
    if(arr2[i]==b[j].first) {ans+=b[j].second; i++;}
    else if(arr2[i]>b[j].first) j++;
    else i++;
  }
  cout<<ans;
return 0;
}
