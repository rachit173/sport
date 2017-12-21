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
#define MAXN 500005
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef struct node{
    ll tot_cnt;
    ll left_free;
    ll right_free;
    node* left;
    node* right;
}node;
node store[10000000];
int stat=0;
ll a[MAXN];
ll b[MAXN];
int L,R;
node* build(int l,int r){
    // cout<<l<<" "<<r<<endl;
    if(r<l) return NULL;
    if(r<=l){
        node *hss = &store[stat++];
        hss->tot_cnt=1;
        hss->left_free = hss->right_free = 1;
        hss->right = hss->left = NULL;
        return hss;
    }
    int mid = l+(r-l)/2;
    node *hss = &store[stat++];
    hss->left = build(l,mid);
    hss->right = build(mid+1,r);
    node *lt = hss->left;
    node *rt =  hss->right;
 
    hss->tot_cnt = lt->tot_cnt+rt->tot_cnt+(lt->right_free*rt->left_free);
    hss->left_free = lt->left_free==(mid-l+1)?(lt->left_free+rt->left_free):lt->left_free;
    hss->right_free = rt->right_free==(r-mid)?(rt->right_free+lt->right_free):rt->right_free;
    // cout<<l<<" "<<r<<" "<<mid<<" "<<hss->tot_cnt<<" "<<hss->left_free<<" "<<hss->right_free<<endl;
    return hss;
}
void update(node *root,int l,int r,int index){
    // cout<<l<<" "<<r<<" "<<index<<endl;
    if(index<l||index>r) return ;
    if(r<=l) {
        if(a[index])
        root->tot_cnt = root->left_free = root->right_free=0;
        else root->tot_cnt = root->left_free = root->right_free=1;
        return ;
    }
    int mid = l + (r-l)/2;
    if(index<=mid){
        // printf("here");
        update(root->left,l,mid,index);
    }
    else{
        update(root->right,mid+1,r,index);
    }
    node *lt = root->left;
    node *rt = root->right;
 
    root->tot_cnt = lt->tot_cnt+rt->tot_cnt+(lt->right_free*rt->left_free);
    root->left_free = lt->left_free==(mid-l+1)?(lt->left_free+rt->left_free):lt->left_free;
    root->right_free = rt->right_free==(r-mid)?(rt->right_free+lt->right_free):rt->right_free;
}
node *srch(node *root,int l,int r,int ql,int qr){
 
    int mid = l + (r-l)/2;
    if(l==ql&&r==qr) return root;
    if(ql>mid) return srch(root->right,mid+1,r,ql,qr);
    if(qr<=mid) return srch(root->left,l,mid,ql,qr);
    node *lt = srch(root->left,l,mid,ql,mid);
    node *rt = srch(root->right,mid+1,r,mid+1,qr);
    node *hss = &store[stat++];
    hss->tot_cnt = lt->tot_cnt+rt->tot_cnt + (lt->right_free*rt->left_free);
    hss->left_free = lt->left_free==(mid-ql+1)?(lt->left_free+rt->left_free):lt->left_free;
    hss->right_free = rt->right_free==(qr-mid)?(rt->right_free+lt->right_free):rt->right_free;
    return hss;
}
node* build1(int l,int r){
    // cout<<l<<" "<<r<<endl;
    if(r<l) return NULL;
    if(r<=l){
        node *hss = &store[stat++];
        hss->tot_cnt=1;
        hss->left_free = hss->right_free = 1;
        hss->right = hss->left = NULL;
        return hss;
    }
    int mid = l+(r-l)/2;
    node *hss = &store[stat++];
    hss->left = build1(l,mid);
    hss->right = build1(mid+1,r);
    node *lt = hss->left;
    node *rt =  hss->right;
 
    hss->tot_cnt = lt->tot_cnt+rt->tot_cnt+(lt->right_free*rt->left_free);
    hss->left_free = lt->left_free==(mid-l+1)?(lt->left_free+rt->left_free):lt->left_free;
    hss->right_free = rt->right_free==(r-mid)?(rt->right_free+lt->right_free):rt->right_free;
    return hss;
}
void update1(node *root,int l,int r,int index){
    // cout<<l<<" "<<r<<" "<<index<<endl;
    if(index<l||index>r) return ;
    if(r<=l) {
        if(b[index])
        root->tot_cnt = root->left_free = root->right_free=0;
        else root->tot_cnt = root->left_free = root->right_free=1;
        return ;
    }
    int mid = l + (r-l)/2;
    if(index<=mid){
        // printf("here");
        update1(root->left,l,mid,index);
    }
    else{
        update1(root->right,mid+1,r,index);
    }
    node *lt = root->left;
    node *rt = root->right;
 
    root->tot_cnt = lt->tot_cnt+rt->tot_cnt+(lt->right_free*rt->left_free);
    root->left_free = lt->left_free==(mid-l+1)?(lt->left_free+rt->left_free):lt->left_free;
    root->right_free = rt->right_free==(r-mid)?(rt->right_free+lt->right_free):rt->right_free;
}
node *srch1(node *root,int l,int r,int ql,int qr){
 
    int mid = l + (r-l)/2;
    if(l==ql&&r==qr) return root;
    if(ql>mid) return srch1(root->right,mid+1,r,ql,qr);
    if(qr<=mid) return srch1(root->left,l,mid,ql,qr);
    node *lt = srch1(root->left,l,mid,ql,mid);
    node *rt = srch1(root->right,mid+1,r,mid+1,qr);
    node *hss = &store[stat++];
    hss->tot_cnt = lt->tot_cnt+rt->tot_cnt + (lt->right_free*rt->left_free);
    hss->left_free = lt->left_free==(mid-ql+1)?(lt->left_free+rt->left_free):lt->left_free;
    hss->right_free = rt->right_free==(qr-mid)?(rt->right_free+lt->right_free):rt->right_free;
    return hss;
}
int main(){
int n,q;
cin>>n>>q>>L>>R;
int type,x,y;
RESET(a,0);
RESET(b,0);
node *head = build(0,n-1);
node* head1 = build1(0,n-1);
// pf1(head->left->tot_cnt);br;
while(q--){
    sc(type);
    sc(x);sc(y);
    if(type==1){
        x--;
        // cout<<x<<endl;
        if(y>R) a[x]=1;
        else a[x]=0;
        if(y>=L) b[x]=1;
        else b[x]=0;
        update(head,0,n-1,x);
        update1(head1,0,n-1,x);
    }
    else{
        x--;
        y--;
        ll l=(y-x+1);
        ll tot = (l*(l+1))/2;
        ll ans = srch(head,0,n-1,x,y)->tot_cnt-srch1(head1,0,n-1,x,y)->tot_cnt;
        // cout<<srch1(head1,0,n-1,x,y)->tot_cnt<<endl;
        // cout<<srch(head,0,n-1,x,y)->tot_cnt<<endl;
        pf1(ans);br;
    }
}
return 0;
}
 