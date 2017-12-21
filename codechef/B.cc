#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)

#define LSOne(S) (S & (-S))

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
const int N=200005;
vector <int> g[N];
int a[N];
int pos[N], to[N];
int kw = 1, w[N];
class BIT {
	int* ft, size;
public:
	// initialize a BIT of n elements to zero
	BIT(int n) {
		size = n;
		ft = new int[n+1];
	}

	~BIT()	{
		delete [] ft;
	}

	// returns sum of the range [1...b]
	int sum(int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	// returns sum of the range [a...b]
	int sum(int a, int b) {
		return sum(b) - (a == 1 ? 0 : sum(a - 1));
	}

	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
	// i.e., increment or decrement kth element by a value v
	void update(int k, int v) {
		for (; k <= size; k += LSOne(k)) ft[k] += v;
	}

    // divide each original frequency by c
	void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};

void dfs(int v, int pr) {
    // cout<<v<<endl;
    pos[v] = kw;
    w[kw++] = a[v];
    for (int j = 0; j < (int) g[v].size(); j++) {
      int u = g[v][j];
    //   pf(u);br;
      if (u != pr) {
        dfs(u, v);
      }
    }
    to[v] = kw - 1;
    return ;
  }
int main(){
    BIT bt(N-5);
    int n, m;
    RESET(w,0);
    RESET(pos,0);
    RESET(to,0);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d",& a[i]);
    }
    for (int i = 0; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int foo, bar;
      scanf("%d %d", &foo, &bar);
      foo; bar;
      g[foo].push_back(bar);
      g[bar].push_back(foo);
    }
    // printf("there");
    dfs(1, -1);
    // printf("here");
    // return 0;
    for(int i=1;i<=n;i++){
        // cout<<i<<" "<<pos[i]<<" "<<a[i];
        bt.update(pos[i],a[i]);
    }
    // return 0;
    char c;
    int x,y;
    while(m--){
        // printf("here");
        scanf("\n%c %d",&c,&x);
        if(c=='U'){
            sc(y);
            w[pos[x]]=y;
        bt.update(pos[x],y-a[x]);
        a[x]=y;
        }
        else{
            pf(bt.sum(pos[x],to[x]));br;
        }
    }
return 0;
}
