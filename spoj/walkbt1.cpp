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
#define 
int N,Q;
int BN;
const int val=256;
int carry;
int carryff;
struct node{
    node():left(NULL),right(NULL){}
    struct node *left;
    struct node *right;
};
typedef struct node node;
struct blk{
    blk():x(0),head(NULL){}
    int x;
    struct node *head;
}
blk X[10005];
int block;
int d;
int tmp;
void add(int C){
    if(C>=N) return ;
    block=C/8;
    d=C%8;
    tmp=1<<d;
    X[block].x+=tmp;
    d=X[block].x/val;
    X[block].x%=val;
    block++;
    while(d>0){
        X[block].x++;
        d=X[block].x/val;
        X[block].x%=val;
    }
    block=N/8;
    d=N%8;
    X[block].x=X[block].x&(~(1<<d));
}
ll fun(node *head,int V[],int st){
    if(st==0) return 0; 
    // if(head==NULL){
    //     head=new node;
    //     head->left=NULL;
    //     head->right=NULL;
    //     head->val=X[st];
    //     pf(head->val);br;
    // if(X[st]==0) return 1+fun(head->left,X,st-1); 
    // else return 1+fun(head->right,X,st-1);
    // }
    // pf(1);sp;
    // pf(head->val);br;
    node *temp;
    
    if(V[st-1]==0) {
        //printf("%p\n",head->left);
        //cout<<0;
        
        if(head->left==NULL){
          //  cout<<0<<endl; 
        head->left=new node;
         //(head->left)->left=NULL;
         //(head->right)->right=NULL;
        return 1+fun(head->left,V,st-1);
        }
        //cout<<1<<endl; 
        return fun(head->left,V,st-1); 
        }
    else {
        //printf("%p\n",head->right);
        //cout<<1;
        if(head->right==NULL){
          //  cout<<0<<endl;
            head->right=new node;
          // (head->left)->left=NULL;
        //(head->right)->right=NULL;
            return 1+fun(head->right,V,st-1);
        }
        //cout<<1<<endl;
        return fun(head->right,V,st-1);
        }
}
ll fun1(int start,int type){
    while(start>=0&&memo[type][X[start].x][start]) start--;
    start++;

    if(X[start].head==NULL) X[start].head=new node;
    return RN-(start*8+fun(X[start].head,X[start].x,8)); 
}
int main(){
    int T;
    cin>>T;
    while(T--){
        sc(N);sc(Q);
        RN=ceil(N*1.0/8)*8;
        RESET(memo,false,sizeof(memo));
        char c;
        ll ans=1;
        int C;
        // node *head=new node;
        // //head.val=0;
        // head->left=NULL;
        // head->right=NULL;
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
                ans+=fun(N/8,0);
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