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
typedef struct node{
    int val;
    struct node* children[10];
}node;
int check;
node* add(char s[],int index,node* root,bool iswordend){
    bool retbool=false;
    if(root!=NULL){
        int t = 0;
        for(int i=0;i<10;i++) if(root->children[i]!=NULL) t+=(root->children[i])->val;
        if(root->val>t) retbool=true;
    }
    if(s[index+1]!='\0'){
        if(root==NULL){
            root = new node;
            for(int i=0;i<10;i++) root->children[i]=NULL;
            if(iswordend) check=1;
            root->val=0;
        }
            root->val++;
            root->children[s[index+1]-'0']=add(s,index+1,root->children[s[index+1]-'0'],retbool);
            return root;
    }
    else{
        //this is the last character tobe inserted
        if(root==NULL){
            root = new node;
            for(int i=0;i<10;i++) root->children[i]=NULL;
            root->val=1;
            if(iswordend) check=1;
            return root;
        }
        else{
            root->val++;
            for(int i=0;i<10;i++) if(root->children[i]!=NULL) check=1;
            return root;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        // return 0;
        node* root;
        root = new node;
        root->val=0;
        // for(int i=0;i<10;i++) root->children[i]=NULL;
        char s[11];
        int n;
        sc(n);
        int opt=0;
        f(i,n){
            scanf("%s",s);
            int temp = s[0]-'0';
            root->val++;
            check = 0;
            root->children[temp] = add(s,0,root->children[temp],false);
            if(check==1){ opt=1; }
        }
        if(opt==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
