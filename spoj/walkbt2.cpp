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
int N,Q;
int carry;
int carryff;
int X[10005];
int block;
int d;
int tmp;
void add(int C){
    if(C>=N) return ;
    block=C/8;
    d=C%8;
    tmp=1<<d;
    X[block]+=tmp;
    d=X[block]/val;
    X[block]%=val;
    block++;
    while(d>0){
        X[block]++;
        d=X[block]/val;
        X[block]%=val;
        block++;
    }
    block=N/8;
    d=N%8;
    X[block]=X[block]&(~(1<<d));
    X[block+1]=0;
}
struct node{
    node():left(NULL),right(NULL),arr(NULL){}
    int *arr; 
    struct node *left;
    struct node *right;
};
typedef struct node node;
ll fun(node *head,int st){
    if(st==0) return 0; 
    
}
void free_memory(node *head){
    if(head==NULL) return;
    free_memory(head->left);
    free_memory(head->right);
    free(head);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        sc(N);sc(Q);
        RESET(X,0);
        char c;
        ll ans=1;
        int C;
        node *head=new node;
        head->x=0;
        head->left=NULL;
        head->right=NULL;
        while(Q--){
            getchar();
            //fflush(stdout);
            c='2';
            while(c!='!'&&c!='?')
                scanf("%c",&c);
            if(c=='!'){
                sc(C);
                add(C);
               //fr(i,N) {pf(X[i]);sp;} br;
                ans+=fun(head,(N/8)+1);
            }                                                                                                                                   
            else{
               // fflush(stdout);
                
                pf1(ans);
                br;
            }
            
        }
        free_memory(head);
    }
return 0;
}