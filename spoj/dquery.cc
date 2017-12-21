#include<bits/stdc++.h>
#include<time.h>
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
#define LSOne(S) (S & (-S))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
int a[100000];
// class BIT {
// 	int* ft, size;
// public:
// 	// initialize a BIT of n elements to zero
// 	BIT(int n) {
// 		size = n;
// 		ft = new int[n+1];
// 	}

// 	~BIT()	{
// 		delete [] ft;
// 	}

// 	// returns sum of the range [1...b]
// 	int sum(int b) {
// 		int sum = 0;
// 		for (; b; b -= LSOne(b)) sum += ft[b];
// 		return sum;
// 	}

// 	// returns sum of the range [a...b]
// 	int sum(int a, int b) {
// 		return sum(b) - (a == 1 ? 0 : sum(a - 1));
// 	}

// 	// update value of the k-th element by v (v can be +ve/inc or -ve/dec)
// 	// i.e., increment or decrement kth element by a value v
//     void update(int k, int v) 
//     {
// 		for (; k <= size; k += LSOne(k)) ft[k] += v;
// 	}

//     // divide each original frequency by c
//     void scaleDown(int c)
//     {
//         for (int i=1 ; i<=size ; i++) ft[i] /= c;
//     }

//     // multiply each original frequency by c
//     void scaleUp(int c)
//     {
//         for (int i=1 ; i<=size ; i++) ft[i] *= c;
//     }
//     void print()
//     {
//         for(int i=1;i<=size;i++) {pf(ft[i]);sp;}
//         br;
//     }
// };
int ft[30005];
int size;
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
void update(int k, int v) 
{
    for (; k <= size; k += LSOne(k)) ft[k] += v;
}

// divide each original frequency by c
void scaleDown(int c)
{
    for (int i=1 ; i<=size ; i++) ft[i] /= c;
}

// multiply each original frequency by c
void scaleUp(int c)
{
    for (int i=1 ; i<=size ; i++) ft[i] *= c;
}
void print()
{
    for(int i=1;i<=size;i++) {pf(ft[i]);sp;}
    br;
}
int arr[1000007];
queue<int> BL[1000007];
int main(){
    clock_t start,end;
    start=clock();
    int n;
    sc(n);
    size=n;
    int u;
    int v;
    // BIT fen(n);
    RESET(ft,0);
    f1(i,1,n+1) sc(a[i]);
    int q;
    sc(q);
    RESET(arr,0);
    vii AL[n+1];
    // vi CL[n+1];
    f(i,q)
    {
        sc(u);sc(v);
        AL[u].pb(ii(v,i));
        // CL[u].pb(0);
    }
    // int b[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(arr[a[i]]==0){
            update(i,1);
            arr[a[i]]=1;
        }
        else{
            BL[a[i]].push(i);
        }
    }
    int ans[q+1]={0};

    // f1(i,1,n+1){
    //     fen.update(i,b[i]);
    // }
    for(int i=1;i<=n;i++)
    {
        // pf(i);sp;pf((int)AL[i].size());br;
        for(int j=0;j<(int)AL[i].size();j++)
        {
            ans[AL[i][j].ss] = sum(i,AL[i][j].ff);
        }
        if(!BL[a[i]].empty())
        {
            update(BL[a[i]].front(),1);
            BL[a[i]].pop();
        }
    }
    f(i,q)
    {
        pf(ans[i]);br;
    }
    //end=clock();
    // printf("%lf",(double)(end-start)/CLOCKS_PER_SEC);
return 0;
}
