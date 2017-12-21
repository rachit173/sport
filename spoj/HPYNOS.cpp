#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int memo[1000];
int breakit(int N){
  int ans=0;
  while(N>0){
    ans+=(N%10)*(N%10);
    N=N/10;
  }
  return ans;
}
int main(){
  int N;
  cin>>N;
  //set<int> s;
  int count=0;
  if(N==1) {
    cout<<1<<endl;
    return 0;
  }
  while(N!=1){
//    cout<<N;
    if(N<1000&&memo[N]>1) {
    cout<<-1<<endl; return 0;
    }
    N=breakit(N);
    memo[N]++;
    count++;
  }
  cout<<count<<endl;
  return 0;
}
