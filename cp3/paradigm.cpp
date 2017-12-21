#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int N=1<<32-1<<21;
  auto asBinary=bitset<32>(N).to_string();
  asBinary(0,asBinary.find_first_not_of('0'));
  cout<<asBinary;
  return 0;
}
