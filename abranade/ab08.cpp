//created by rachit
//compiled using the gcc compiler
//the code covers the use of initialisation list which 
//are compulsory to use with const declaration of datatypes and
//also when using nested structures with constructors
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
  struct Point{
    const double x,y;
    Point(double p=0,double q=0):x(p),y(q)
    {}
  };
  struct Circle{
     Point center;
     double radius;
     Circle(double x,double y,double r):center(Point(x,y)),radius(r)
     {
     }
  };
using namespace std;
int main()
{
  Circle c1(2.0,3.0,5.0);
  cout<<c1.center.x<<c1.center.y<<c1.radius<<endl;
  return 0;
}

