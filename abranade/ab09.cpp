//created by rachit
//compiled using the gcc compiler
//this code gives a coverage of static data members
//they can be decalred many times,this does not alter their value
//only their definiition changes their value
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<string>
#define FORF(n) for(int xxz=0;xxz<n;xxz++)
#define FORR(n) for(int xxz=n-1;xxz>=0;xxz--)
//mistakes
  #define pritnf printf
struct Point{
  double x,y;
  static int counter;                           //only declares
  Point(){
    counter++;
  }
  Point(double x1,double y1):x(x1),y(y1){
    counter++;}
};
int Point::counter=0;                           //actually defines
using namespace std;
int main()
{
  Point a,b,c(1,2);
  cout<<a.counter<<endl;
  return 0;
}

