#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d",a)
#define sc1(a) scanf("%lld",&a)
#define pf1(a) printf("%lld",a)
#define sc2(a) scanf("%d %d",&a.first,&a.second)
#define br printf("\n")
#define sp printf(" ")
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,st,n) for(int i=st;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod 1000000007
#define mod1 1000000009
#define oo 1000000000
#define EPS 1e-15
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const double PI = acos(-1);
struct point_i{
    int x;
    int y;
    point_i(){x= y= 0;}
    point_i(int _x,int _y): x(_x),y(_y) {}
    bool operator <(point_i other){
        if(x!=other.x) return x<other.x;
        return y<other.y;
    }
    bool operator == (point_i other) const {
        return x==other.x&&y==other.y;
    }
};
struct point {
    double x,y;
    point(){x = y = 0;}
    point(double _x,double _y): x(_x),y(_y) {}
    bool operator <(point other) const{
        if(abs(x-other.x)>EPS)
        return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return abs(x-other.x)<EPS&&abs(y-other.y)<EPS;
    }
};
double dist(point_i a,point_i b) {
    return hypot(a.x-b.x,a.y-b.y);
}
double dist(point a,point b){
    return hypot(a.x-b.x,a.y-b.y);
}
point rotate(point p,double theta){
    double rad = (theta * PI)/180.0;
    return point(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad)+p.y*cos(rad));
}
struct line {
    double a,b,c;
}
line pointsToLine(point p1,point p2){
    line l;
    if(abs(p1.x-p2.x)<EPS){
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b  = 1.0;
        l.c = -double(l.a*p1.x) - p1.y;
    }
    return l;
}
bool areParallel(line l1,line l2){
    return abs(l1.a-l2.a)<EPS && abs(l1.b - l2.b);
}
bool areSame(line l1,line l2){
    return areParallel(l1,l2) && abs(l1.c - l2.c)<EPS;
}
int main(){
    point a(2,3);
    point b(3,-2);
    if(a==rotate(b,90)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
return 0;
}
