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
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll memo[300000][2];
int n;
// ll dp(int n,int tp){

// }
template<class F> using Point = pair<F,F>;
template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }
template <class F>
F area(const Polygon<F>& poly) {
  int n = static_cast<int>(poly.size());
  F area = F(0);
  for (int i = 0; i < n; ++i)
    area += poly[i].x * (poly[prev(i, n)].y - poly[next(i, n)].y);
  return area;
}
template <class F>
Polygon<F> convexHull(Polygon<F> points) {
  sort(begin(points), end(points));
  Polygon<F> hull;
  hull.reserve(points.size() + 1);
  for (int phase = 0; phase < 2; ++phase) {
    auto start = hull.size();
    for (auto& point : points) {
      while (hull.size() >= start+2 &&
             ccw(point, hull.back(), hull[hull.size()-2]) <= 0)
        hull.pop_back();
      hull.push_back(point);
    }
    hull.pop_back();
    reverse(begin(points), end(points));
  }
  if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
  return hull;
}
int main(){
    cin>>n;
    Polygon<ll> poly(n);
    vi c(n);
    f(i,n) {
        sc1(poly[i].ff);
        sc1(poly[i].ss);
        sc(c[i]);
    }
    // auto x_bounds = minmax_element(s.begin(),s.end());
    // auto y_bounds = minmax_element(w.begin(),w.end());
    // pf1(min(dp(0,0),dp(0,1)));
    Polygon<ll> hull = convexHull(poly);
    f(i,hull.size()){
        cout<<hull[i].ff<<" "<<hull[i].ss<<endl;
    }
return 0;
}
