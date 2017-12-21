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
#define pritnf printf
#define br printf("\n")
using namespace std;
typedef struct{
  double x;
  double y;
  double z;
}V3;
V3 make_v3(double x,double y,double z){
  V3 v;
  v.x=x;
  v.y=y;
  v.z=z;
  return v;
}
V3 sum(const V3 *v1,const V3 *v2)
//const prevents changing the value of pointer at memory adress and 
//also speedens the process as only adress is passed instead of copying the entire array
{        
  return make_v3(v1->x+v2->x,v1->y+v2->y,v1->z+v2->z);
}
//yeah operator overloading will make my cpp more functional
//addition of vectors
V3 operator+ (V3 a,V3 b){
  return make_v3(a.x+b.x,a.y+b.y,a.z+b.z);
}
V3 operator- (V3 a,V3 b){
  return make_v3(a.x-b.x,a.y-b.y,a.z-b.z);
}
//dot product of vectors
double operator* (V3 a,V3 b){
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
//scalar multiplication with vector
V3 operator* (V3 a,double t){
  return make_v3(a.x*t,a.y*t,a.z*t);
}
V3 operator* (double t,V3 a){
  return make_v3(t*a.x,t*a.y,t*a.z);
}
//note this can be considered as the most interesting part of the code
ostream & operator<<(ostream & ost,V3 v){
  ost<<"(" <<v.x<<","<<v.y<<","<<v.z<<")";
  return ost;
}
int main()
{
  V3 v1,v2,v3;
  v1=make_v3(2.0,4.0,0.5);
  v2=make_v3(1.0,2.5,4.5);
  cout<<v1+v2<<endl;
  cout<<v1*v2<<endl;
  cout<<v1*4.5<<endl;
  //cout<<v1-v2<<endl;
  cout<<v1+4*v2<<endl;
  return 0;
}

