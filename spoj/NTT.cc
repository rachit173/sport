#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<complex>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;



int n;
vector<LL> num;
VI divisors;


vector<int> Prime;
int mark[4000002];

void sieve(int n)
{
	int i,j,limit=sqrt(n*1.)+2;

	mark[1] = 1;
	for(i=4;i<=n;i+=2) mark[i]=1;

	Prime.push_back(2);
	for(i=3;i<=n;i+=2)
		if(!mark[i])
		{
			Prime.push_back(i);

			if(i<=limit)
			{
				for(j=i*i;j<=n;j+=i*2)
				{
					mark[j] = 1;
				}
			}
		}
}

int isprime(LL p)
{
	assert(p <= 1000000000);
	if(p <= 4000000) return !mark[p];
	for(int i = 0; Prime[i] * Prime[i] <= p; i++)
		if(p % Prime[i] == 0) 
			return 0;
	return 1;
}

LL bigmod(LL a, LL b, LL m)
{
	if(b == 0) return 1 % m;
	LL x = bigmod(a, b >> 1, m);
	x = (x * x) % m;
	if(b & 1) x = (x * a) % m;
	return x;
}

/*
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<base> bluestein(LL Prime, LL Root)
{
	int i, m;

	if(n & (n - 1));
	else
	{
		vector<base> ret = x;
		fft(ret, 0);
		return ret;
	}

	vector<base> h(n);
	double ang = 2 * PI / n;
	for(i = 0; i < n; i++)
		h[i] = base(cos(- ang * i * i / 2), sin(- ang * i * i / 2));

	for(m = 1; m < 2 * n - 2; m *= 2);
	vector<base> h2(m);
	for(i = 0; i < n; i++) h2[i] = h[i];
	for(i = m - n + 2; i < m; i++) h2[i] = h[m - i];
	for(i = n; i < m - n + 2; i++) h2[i] = 0;

	vector<base> hcap = h2;
	fft(hcap, 0);

	vector<base> y2(m);
	for(i = 0; i < n; i++) y2[i] = x[i] * base( cos(ang * i * i / 2), sin(ang * i * i / 2) );
	for(i = n; i < m; i++) y2[i] = 0;

	vector<base> Y = y2;
	fft(Y, 0);

	vector<base> Zcap(m);
	for(i = 0; i < m; i++) Zcap[i] = hcap[i] * Y[i];

	vector<base> Z = Zcap;
	fft(Z, 1);

	vector<base> X(n);
	for(i = 0; i < n; i++) X[i] = Z[i] * base( cos(ang * i * i / 2), sin(ang * i * i / 2) );

	return X;
}

LL primes[] =	{7340033, 30539777, 241827841};
LL root[] =		{3068761, 17592176, 129322846};
*/
LL rev[1<<17 + 5];
void fft(vector<LL> &a, int invert, LL mod, LL root)
{
	int n = (int) a.size();
	int i, j;

	for (i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

/*	
		memset(rev, 0, n * sizeof(int));
for(i = 0; (1<<i) <= n; i++) {
for(j = 0; j < (1<<i); j++){
rev[j] *= 2;
rev[j | 1 << i] = rev[j] + 1;
}
}
	FORN(i, n){
if (rev[i] < i) swap(a[i], a[rev[i]]);
}*/
	int root_pw = n;//1<<17;
	for (int len=2; len<=n; len<<=1) {
		LL wlen = root;
		for (i=len; i<root_pw; i<<=1)
			wlen = LL (wlen * wlen % mod);
		for (i=0; i<n; i+=len) {
			LL w = 1;
			for (int j=0; j<len/2; ++j) {
				LL u = a[i+j],  v =  (a[i+j+len/2] * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = LL (w * wlen % mod);
			}
		}
	}
	if (invert) {
		LL nrev = bigmod(n,mod-2,mod);
		for (int i=0; i<n; ++i)
			a[i] = LL (a[i] * nrev % mod);
	}
}

void convolution(vector<LL> &a1, vector<LL> &b1, LL p)
{
	LL prime1 = 767164417, w1 = 132088491;
	LL prime2 = 1031667713, w2 = 3198193;

//LL prime1 = 983826433;
//LL w1 = 53;
//LL prime2 = 949616641;
//LL w2 = 137;

	vector<LL> a2 = a1, b2 = b1;
	int n = SZ(a1), i;

	while(n < (1<<17)) n *= 2, w1 = (w1 * w1) % prime1, w2 = (w2 * w2) % prime2;
	fft(a1, 0, prime1, w1);
	fft(a2, 0, prime2, w2);
	fft(b1, 0, prime1, w1);
	fft(b2, 0, prime2, w2);

	n = SZ(a1);
	FORN(i, n) 
	{
		a1[i] = (a1[i] * b1[i]) % prime1;
		a2[i] = (a2[i] * b2[i]) % prime2;
	}

	fft(a1, 1, prime1, bigmod(w1, prime1 - 2, prime1));
	fft(a2, 1, prime2, bigmod(w2, prime2 - 2, prime2));

	LL a, b;
	LL factor = bigmod(prime1, prime2 - 2, prime2);
	FORN(i, n)
	{
		a = a1[i];
		b = ((a2[i] - a) * factor) % prime2;
		if(b < 0) b += prime2;
		a1[i] = (a + b * prime1)%p;
	}
}

void bluestein(vector<LL> &A, LL w_half, LL w, LL p)
{
	int m;
	for(m = 1; m < 2*n; m <<= 1);
//	m = 1<<17;
	LL inv_w_half = bigmod(w_half, p - 2, p);

	int i;
	vector<LL> a(m, 0), b(m, 0);
	FORN(i, n)
	{
		a[i] = (A[i] * bigmod(inv_w_half, i * i, p)) % p;
		b[i] = bigmod(w_half, i * i, p);
		if(i) b[m - i] = b[i];
	}

	convolution(a, b, p);
	//a * b

	FORN(i, n) A[i] = (a[i] * bigmod(inv_w_half, i * i, p)) % p;
}

int solve(LL g, LL p) //returns 1 if determinant 0, otherwise 0.
{
	vector<LL> A = num;
	int i;
	for(i = SZ(A) - 1; i >= 0; i--)
		A[i] = (p + A[i])%p;

	LL w_half, w;
	w_half = g;
	w = (g * g) % p;
	
	bluestein(A, w_half, w, p); //populate all f(w_j) in A
	
	LL det = 1;
	for(i = 0; i < n; i++) det = (det * A[i]) % p;
	return det == 0;
}

int primitive_root(LL g, LL p)
{
	if(bigmod(g, n* 2, p) != 1) return 0;
	for(int i = SZ(divisors) - 1; i >= 0; i--)
		if(bigmod(g, divisors[i], p) == 1)
			return 0;
	return 1;
}

int solve()
{
	if(n == 1) return num[0];
	if(n == 2) return num[0] * num[0] - num[1] * num[1];
	if(n == 3) return (num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2] - 3 * num[0] * num[1] * num[2] != 0);

	divisors.clear();
	int i, n2 = 2 * n;
	for(i = 2; i * i <= n2; i++)
	{
		if(n2 % i == 0) divisors.push_back(i);
		if(i * i != n2) divisors.push_back(n2 / i);
	}


	int p, g, cnt = 0;
	for(p = (2000000 / n2) * n2 + 1; ; p += n2)
	{
		if(!isprime(p)) continue;
		for(g = 2; g <= 100; g++)
		{
			if(primitive_root(g, p)) break;
		}

		if(g > 100) continue;

		if(solve(g, p)) return 0;
		cnt++;
		if(cnt == 3) return 1;
	}

	assert(0);
	return 0;
}

int main()
{
    vector<LL> x(10),y(10);
    for(int i=0;i<4;i++) x[i]=y[i]=1;
    cout<<"Start"<<endl;
    convolution(x,y,113);
    for(int i=0;i<10;i++) cout<<x[i]<<" ";
    cout<<endl;
	return 0;
}