//created by rachit
//compiled using the gcc compiler
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
#define FORF(n) for(int xxz=0;xxz<n;xxz++)
#define FORR(n) for(int xxz=n-1;xxz>=0;xxz--)
//mistakes
  #define pritnf printf
using namespace std;
typedef struct V3
{
  double x,y,z;
  V3(double p,double q,double r){   //constructor 1
    x=p;
    y=q;
    z=r;
  }
  V3(double p,double q){
    x=p;
    y=q;
    z=0;
  }
  V3(){                              //constructor 2
    x=y=z=0;
  }
  double length(){
    return sqrt(x*x+y*y+z*z);
  }
  V3 operator+ (V3 b){
    return V3(x+b.x,y+b.y,z+b.z);
  }
  V3 operator- (V3 b){
    return V3(x-b.x,y-b.y,z-b.z);
  }
  V3 operator* (double t){
    return V3(x*t,y*t,z*t);
  }
};
int main()
{
  //here v2 is initialised to null vector
  V3 v1(2.0,3.4,4.5),v2;
  return 0;
}


