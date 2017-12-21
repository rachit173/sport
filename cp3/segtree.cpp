#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<ll> vi;
//successfully upated the segment tree
struct node{
    ll val;
    int start,end,mid;
    struct node *left,*right;
};
typedef struct node node; 
ll build(node *head,vi &a,int l,int r){
    if(r-l<2){
        head->val=a[l];
        head->start=l; head->end=l;head->mid=l;
        head->left=head->right=NULL;
        return head->val;
    }
    int mid=(l+r)/2;
    head->start=l;
    head->end=r-1;
    head->left=new node;
    head->right=new node;
    head->mid=mid;
    head->val=build(head->left,a,l,mid)+build(head->right,a,mid,r);
    return head->val;
}
//the query is 0-indexed and inclusive of both limits
ll query(node *head,int L,int R){
    int start=head->start; int end=head->end; int mid=head->mid;
    if(start==L&&end==R) return head->val;
    if(L>=mid) return query(head->right,L,R);
    else if(R<mid) return query(head->left,L,R);
    else
        return query(head->left,L,mid-1)+query(head->right,mid,R);
}
void update(node *head,int i,int x){
    if(head==NULL) return;
    if(head->start<=i&&i<=head->end) {head->val+=x;
    update(head->left,i,x);
    update(head->right,i,x);
    }
    else return;
}
int main(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
        node head;
    build(&head,a,0,n);
    int L,R;
    ll ans=0;
    int type;
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==0){
        cin>>L>>R;
        ans=query(&head,L,R);
        cout<<ans<<endl;
        }
        else{
            cin>>L>>R;                  //here L is the index of update and R is the value of update
            update(&head,L,R-a[L]);
        }
    }
    return 0;
}
