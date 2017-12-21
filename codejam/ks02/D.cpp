#include<bits/stdc++.h>
using namespace std;
vector<char> v(1000000,'a');
struct node{
    bool used;
    //string s;
    int start,end,mid;
    struct node *left;
    struct node *right;
};
typedef struct node node;
void build(node *head,int l,int r){
    if(r-l<2){
        //head->s="A";
        head->used=false;
        head->start=l; head->end=l; head->mid=l;
        head->left=head->right=NULL;
        return;
    }
    int mid=(l+r)/2;
    head->start=l;
    head->end=r-1;
    head->left=new node;
    head->right=new node;
    head->mid=mid;
    head->used=false;
    build(head->left,l,mid);
    build(head->right,mid,r);
}
void bin(node *head,int L,int R,int st,string s){
    if(L>R||st>=s.size()) return;
    cout<<L<<" "<<R<<endl;
    int start=head->start; int end=head->end;int mid=head->mid;
    if(head->used==true) return;
    if(start==L&&end==min(R,L+(int)s.size()-st)){
        for(int i=L;i<=end;i++){
            v[i]=s[st+i-L];
            cout<<v[i]<<" "<<i<<",";
        }
        cout<<endl;
        head->used=true;
      //  update(head);
        return;
    }
    else{
        bin(head->left,L,min(mid-1,R),st,s);
        bin(head->right,max(mid,L),R,st+mid-L,s);
    }
}
// void update(node *head){
//     if(head==NULL) return;
//     head->used=true;
//     update(head->left);
//     update(head->right);
// }
int main(){
    int n;
    cin>>n;
    string s;
    int t;
    int x;
    int ans=0;
    node head;
    build(&head,0,1000000);
    while(n--){
        cin>>s;
        cin>>t;
        for(int i=0;i<t;i++){
        cin>>x;
        x--;
        cout<<s.size()<<endl;
        int R=x+s.size();
        ans=max(ans,R);
       // return 0;
        bin(&head,x,R-1,0,s);
        }
    }
    for(int i=0;i<ans;i++)
    cout<<v[i];
    cout<<endl;
    return 0;
}