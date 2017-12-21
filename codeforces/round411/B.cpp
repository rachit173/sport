#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int,int> ii;
typedef vector<int > vi;
typedef vector<ii> vii;
int main(){
  int n;
  cin>>n;
  vector<char> a(n);
  a[0]='a';
  a[1]='a';
  for(int i=2;i<n;i++){
    if(a[i-2]=='a')a[i]='b';
    else a[i]='a';
  }
  for(int i=0;i<n;i++)
    printf("%c",a[i]);
  return 0;
}
