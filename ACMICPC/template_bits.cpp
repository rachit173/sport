#include<bits/stdc++.h>
using namespace std;
//bit manip functions---------------
#define isOn(S, j) (S & (1 << j))		//check if the bit is on in the postion 
#define setBit(S, j) (S |= (1 << j)//set the bit in a number to one at some position j(0-based)
#define clearBit(S, j) (S &= ~(1 << j))	//set the bit in a number to zero at some position 
#define toggleBit(S, j) (S ^= (1 << j))//toggle the bit in a number at some position 
#define lowBit(S) (S & (-S))		//find the rightmost one bit in a number ex:in 1010 ->0010 
#define setAll(S, n) (S = (1 << n) - 1)	//set first n right bits in 000000... to 1

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
//---------------------------------
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
int main(){

return 0;
}
