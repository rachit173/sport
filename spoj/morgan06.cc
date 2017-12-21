#include<bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// #include<vector>
// #include<string>
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
typedef pair<int,int> ii;
typedef vector<ii> vii;

typedef vector<ll> VI;
long double PI = acosl(0) * 2;
ll inv(ll p1,int pow1,ll cmod){
    // cout<<"power "<<pow1<<" "<<p<<endl;
    ll ret = 1;
    ll tmp=p1%cmod;
    while(pow1>0){
        if(pow1%2) ret = (ret*tmp)%cmod;
        tmp=(tmp*tmp)%cmod;
        pow1 = pow1>>1;
    }
    // cout<<ret<<endl;
    return ret%cmod;
}
class cmplx
{
public:
	long long a, b;
	cmplx() {a = 0; b = 0;}
	cmplx(ll na, ll nb) {a = na; b = nb;}
	const cmplx operator+(const cmplx &c) const
		{return cmplx((a + c.a)%mod, (b + c.b)%mod);}
	const cmplx operator-(const cmplx &c) const
		{return cmplx((a - c.a+mod)%mod, (b - c.b+mod)%mod);}
	const cmplx operator*(const cmplx &c) const
		{return cmplx((a*c.a)%mod , 0);}
	const cmplx operator/(const cmplx &c) const
		{return cmplx((a*inv(c.a,mod-2,mod))%mod , 0);}
	long long magnitude() {return a;}
	// void print() {printf("(%.3f %.3f)\n", a, b);}
};

class FFT
{
public:
	vector<cmplx> data;
	vector<cmplx> roots;
	VI rev;
	ll s, n;

	void setSize(int ns)
	{
		s = ns;
		n = (1 << s);
		ll i, j;
		rev = VI(n);
		data = vector<cmplx> (n);
		roots = vector<cmplx> (n+1);
		for (i = 0; i < n; i++)
			for (j = 0; j < s; j++)
				if ((i & (1 << j)) != 0)
					rev[i] += (1 << (s-j-1));
		roots[0] = cmplx(1, 0);
		cmplx mult = cmplx(cosl(2*PI/n), sinl(2*PI/n));
		for (i = 1; i <= n; i++)
			roots[i] = roots[i-1] * mult;
	}

	void bitReverse(vector<cmplx> &array)
	{
		vector<cmplx> temp(n);
		ll i;
		for (i = 0; i < n; i++)
			temp[i] = array[rev[i]];
		for (i = 0; i < n; i++)
			array[i] = temp[i];
	}

	void transform(bool inverse = false)
	{
		bitReverse(data);
		ll i, j, k;
		for (i = 1; i <= s; i++) {
			ll m = (1 << i), md2 = m / 2;
			ll start = 0, increment = (1 << (s-i));
			if (inverse) {
				start = n;
				increment *= -1;
			}
			cmplx t, u;
			for (k = 0; k < n; k += m) {
				ll index = start;
				for (j = k; j < md2+k; j++) {
					t = roots[index] * data[j+md2];
					index += increment;
					data[j+md2] = data[j] - t;
					data[j] = data[j] + t;
				}
			}
		}
		if (inverse)
			for (i = 0; i < n; i++) {
				data[i].a /= n;
				data[i].b /= n;
			}
	}

	static VI convolution(VI &a, VI &b)
	{
		int alen = a.size(), blen = b.size();
		int resn = alen + blen - 1;	// size of the resulting array
		ll s = 0, i;
		while ((1 << s) < resn) s++;	// n = 2^s
		ll n = 1 << s;	// round up the the nearest power of two

		FFT pga, pgb;
		pga.setSize(s);	// fill and transform first array
		for (i = 0; i < alen; i++) pga.data[i] = cmplx(a[i], 0);
		for (i = alen; i < n; i++)	pga.data[i] = cmplx(0, 0);
		pga.transform();

		pgb.setSize(s);	// fill and transform second array
		for (i = 0; i < blen; i++)	pgb.data[i] = cmplx(b[i], 0);
		for (i = blen; i < n; i++)	pgb.data[i] = cmplx(0, 0);
		pgb.transform();

		for (i = 0; i < n; i++)	pga.data[i] = pga.data[i] * pgb.data[i];
		pga.transform(true);	// inverse transform
		VI result = VI (resn);	// round to nearest integer
		for (i = 0; i < resn; i++)	result[i] = (ll) (pga.data[i].a + 0.5);

		int actualSize = resn - 1;	// find proper size of array
		while (result[actualSize] == 0)
			actualSize--;
		if (actualSize < 0) actualSize = 0;
		result.resize(actualSize+1);
		return result;
	}
};
void modit(VI& a){
    f(i,a.size()) a[i] = a[i]%mod;
}
ll haha[3000];
ll baba[3000];
VI gaga[251];
ll memo1[251];
int main()
{   
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    RESET(memo1,0);
    RESET(haha,0);
    RESET(baba,0);
    VI a = VI (10);
    VI tmp;
	for (int i = 0; i < 10; i++)
        a[i] = 1;
    gaga[0]=VI(1,1);
    memo1[0] = s[0]-'0';
    for(int i=1;i<s.size();i++){
        memo1[i] = memo1[i-1]+s[i]-'0';
    }
    memo1[s.size()] = memo1[s.size()-1];
    for(int i=0;i<s.size();i++){
    int t = memo1[s.size()-1]-memo1[i];
    int k = s[i] - '0';
    // cout<<s[i]<<" "<<t<<" "<<k<<endl;
    tmp.resize(t+k,0);
    for(int j=0;j<k;j++){
        tmp[t+j] = 1;
    }
    if(i>0)
    gaga[i] = FFT::convolution(gaga[i-1], a);
    // modit(gaga[i]);
    VI b;
    if(i>0) b = FFT::convolution(gaga[i],tmp);
    else b = tmp;
    	// for (int j = 0; j < b.size(); j++)
        // printf("%lld ",b[j]);
        // cout<<endl;
    // modit(b);
    for(int j=0;j<b.size();j++) haha[j]=(haha[j]+b[j]);
}
haha[memo1[s.size()-1]]++;
// f(i,30) cout<<haha[i]<<" ";
// br;
baba[0]=haha[0];
for(int i=1;i<3000;i++) baba[i] = (baba[i-1] + haha[i]); 
ll ans=0;
for(int i=2999;i>0;i--) ans=(ans+(haha[i]*baba[i-1]));
cout<<ans<<endl;
/* 1 8 34 104 259 560 1092 1968 3333
	5368 8052 11120 14259 17104 19234 20168 19361 16200 10000*/
	// for (int i = 0; i < gaga[1].size(); i++)
	// 	printf("%lld ", gaga[1][i]);
	return 0;
}

