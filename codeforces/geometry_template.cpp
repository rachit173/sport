#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2333;
const double INF = 1e17;
struct point
{
	double x, y;
	point(){}
	point(double X, double Y) : x(X), y(Y){}
	void input()
	{
		scanf("%lf %lf", &x, &y);
	}
}P[MAXN];
point operator+(const point & a, const point & b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(const point & a, const point & b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator*(const point & a, const double & k)
{
	return point(a.x * k, a.y * k);
}
double operator*(const point & a, const point & b )
{
	return a.x * b.y - a.y * b.x;
}
double dis(const point & a, const point & b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		P[i].input();
	for(int i = n + 1; i <= n * 2; i++) 
		P[i] = P[i - n];
	double ans = INF;
	for(int i = 1; i <= n; i++) 
	{
		double tmp = (P[i + 2] - P[i]) * (P[i + 1] - P[i]) / 2;
		ans = min(ans, tmp / dis(P[i], P[i + 2]));
	}
	printf("%.10f\n", ans);
	return 0;
}
