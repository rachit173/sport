#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<sstream>
using namespace std;
int main(int argc,char **argv){
  float x,y;
  int a;
  string s;
  stringstream(argv[1])>>x;
  stringstream(argv[2])>>y;
  stringstream(argv[3])>>a;
  cout<<x+y<<a<<endl;

  return 0;
}
                                                                    

