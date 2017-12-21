#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<int,int> vii;
int main()
{
  int n;
  cin>>n;
  vi a(n);
  vi b(n);
  for(int i=0;i<n;i++)
  { 
    cin>>a[i]>>b[i];
    if(a[i]!=b[i]){
      cout<<"rated";
      return 0;
    }
  }
  for(int i=1;i<n;i++)
  {
    if(a[i-1]<a[i]){
      cout<<"unrated";
      return 0;
    }
  }
  cout<<"maybe";
  return 0;
}
