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
#define oo 12345678987654321
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef struct node{
    ll val;
    ll tot_max;
    ll left_max;
    ll right_max;
    // int tp=0;
    node *left;
    node *right; 
}node;
int N;
int QL,QR;
ll a[123456];
node* build(int l,int r){
    // cout<<l<<r;
    //exit(0);
    if(r<l) return NULL;
    if(r-l<1) {
        node *hss = new node;
        hss->val=hss->tot_max=hss->left_max=hss->right_max=a[l];
        hss->right=hss->left=NULL;
        return hss;
    }
    int mid = l+(r-l)/2;
    node *hss = new node;
    hss->left = build(l,mid);
    hss->right = build(mid+1,r);
    node *lt=hss->left;
    node *rt=hss->right;
    // if(lt==NULL||rt==NULL) {cout<<"hi"; return NULL;}
    hss->val = lt->val+rt->val;
    ll tmp = lt->right_max + rt->left_max;
    tmp = max(tmp,max(lt->right_max,rt->right_max));
    hss->tot_max = max(tmp,max(lt->tot_max,rt->tot_max));
    hss->left_max = max(lt->left_max,lt->val + rt->left_max);
    hss->right_max = max(rt->right_max,rt->val + lt->right_max);
    return hss;
}
void update(node *root,int l,int r,int index){
    if(index<l||index>r) return ;
    if(r-l<1) {
        root->val=root->tot_max=root->left_max=root->right_max = a[index];
        return ;
    }
    int mid = l + (r-l)/2;
    if(index<=mid){
        update(root->left,l,mid,index);
        
    }
    else{
        update(root->right,mid+1,r,index);
    }
    node *lt = root->left;
    node *rt = root->right;
    root->val = lt->val+rt->val;
    ll tmp = lt->right_max + rt->left_max;
    tmp = max(tmp,max(lt->right_max,rt->right_max));
    root->tot_max = max(tmp,max(lt->tot_max,rt->tot_max));
    root->left_max = max(lt->left_max,lt->val + rt->left_max);
    root->right_max = max(rt->right_max,rt->val + lt->right_max);
}
node* srch(node *root,int l,int r,int ql,int qr){ 
    //return NULL;
    int mid = l + (r-l)/2;
    //cout<<l<<" "<<r<<" "<<mid<<" "<<ql<<" "<<qr<<",";
    // exit(0);
    if(l==ql&&r==qr) return root;
    if(ql>mid) return srch(root->right,mid+1,r,ql,qr);
    if(qr<=mid) return srch(root->left,l,mid,ql,qr); 
    node *lt = srch(root->left,l,mid,ql,mid);
    node *rt = srch(root->right,mid+1,r,mid+1,qr);
    node *hss = new node;
    ll tmp = lt->right_max + rt->left_max;
    tmp = max(tmp,max(lt->right_max,rt->right_max));
    hss->tot_max = max(tmp,max(lt->tot_max,rt->tot_max));
    hss->left_max = max(lt->left_max,lt->val + rt->left_max);
    hss->right_max = max(rt->right_max,rt->val + lt->right_max);
    // if(lt->val==oo) free(lt);
    // if(rt->val=oo) free(rt);
    return hss;
}
int main(){
    cin>>N; 
   // cout<<N;
    f(i,N) sc1(a[i]);
    //return 0;
    node *head = build(0,N-1);
    // return 0;
    int M;
    sc(M);
    
    int opt=1;
    int q1,q2;
    int u;
    ll up;
    f(i,M){
        sc(opt);
        if(opt==0){
            sc(u); sc1(up);
            u--;
            // ll val = up - a[u];
            a[u] = up;
            update(head,0,N-1,u);
        }
        else{
            sc(q1);
            sc(q2);
            q1--;q2--;
            //pf(q1);pf(q2);
           // if(head==NULL) cout<<"Yes";
           //pf1(head->val);
            pf1(srch(head,0,N-1,q1,q2)->tot_max);br;
            //pf1(ans->tot_max);
        }
    }  
return 0;
}
