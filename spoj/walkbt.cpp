#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<err.h>
using namespace std;
#define TIME_LIMIT 2
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
//bitset <100005> X;
stack<ii> stk;
struct node{
    node():num(0),left(NULL),right(NULL){}
    int num;
    struct node *left;
    struct node *right;
};
typedef struct node node;
struct lstNode{
    lstNode():type(0),num(0),next(NULL){}
    int type;
    int num;
    struct lstNode *next;
};
static int nodenum=0;
static int lstNodenum=0;
node nodeheap[40000000];
lstNode lstNodeheap[40000000];
void add(int C,lstNode *head){
    if(C>=N) return ;
    int k=0;
    int tmp;
    lstNode* tmpNode;
    while(head!=NULL){
     //  pf(head->num);sp;pf(k);
        if(C>=k+head->num){
            k=k+head->num;
            head=head->next;
        }
        else{
     //       pf(head->type);
            if(head->type==0){
                if(C==k){
                    head->type=1;
                    tmp=head->num-1;
                    head->num=1;
                    tmpNode=head->next;
                    if(tmp==0){
                        return ;
                    }
                    head->next=new lstNode;
                    head=head->next;
                    head->type=0;
                    head->num=tmp;
                    head->next=tmpNode;
                    return ;
                }
                tmp=head->num;
                head->num=C-k;
                tmp=tmp-(C-k+1);
                //cout<<tmp<<" "<<head->num<<endl;
                tmpNode=head->next;
                //printf("%p\n",head->next);
                head->next=new lstNode;
                //printf("%p\n",head->next);
                head=head->next;
                //printf("%p\n",head);
                head->type=1;
                head->num=1;
                if(tmp==0){
                    head->next=tmpNode;
                    return ;
                }
                head->next=new lstNode;
                //printf("%p\n",head->next);
                head=head->next;
                head->type=0;
                head->num=tmp;
                head->next=tmpNode;
                return ;
            }
            else{
                head->type=0;
                k+=head->num;
                C+=head->num;
                head=head->next;
            }
        }
    }
}
// void defragment(lstNode *head){
//     lstNode *tmpNode;
//     lstNode *freeNode;
//     tmpNode=head;
//     int k=tmpNode->num;
//     while(head->next!=NULL){
//         if(head->type==1){
//             tmpNode->num=k;
//             tmpNode=head->next;
//             head=head->next;
//             k=head->num;
//         }
//         else{
//             k+=head->num;
//             freeNode=head;
//             head=head->next;
//             //free(freeNode);
//         }
//     }
//     if(head->type==1){
//         tmpNode->num=k;
//     }
//     else{
//         k+=head->num;
//         tmpNode->num=k;
//         //free(head);
//     }
// }
void print(lstNode *head){
    printf("Linked list : \n");
    printf("(%d*%d)",head->type,head->num);
    head=head->next;
    while(head!=NULL){
        printf("-->(%d*%d)",head->type,head->num);
        head=head->next;
    }
}
ii tmp;
ll update(node *head){
    if(stk.empty())return 0;
    tmp=stk.top();
    if(tmp.ff==0){
        head->left=&nodeheap[nodenum++];
        head=head->left;
        head->num=tmp.ss;
        stk.pop();
        return tmp.ss+update(head);
    }
    else{
        head->right=&nodeheap[nodenum++];
        head=head->right;
        head->num=tmp.ss;
        stk.pop();
        return tmp.ss+update(head);
    }
}
ll fun(node *head){
    if(stk.empty()) return 0;
    tmp=stk.top();
    //cout<<tmp.ff<<" "<<tmp.ss<<" "<<head->num<<endl;
    if(tmp.ff==0){  
    if(tmp.ss>=head->num){
        tmp.ss-=head->num;
        stk.pop();
        stk.push(tmp);
        if(tmp.ss>0){ 
        if(head->left==NULL) return update(head);
        else return fun(head->left);
        }
        else{
            stk.pop();
            if(head->right==NULL) return update(head);
            else return fun(head->right);
        }
    }
    else{
            head->num=head->num-tmp.ss;
            node *tmpNode=&nodeheap[nodenum++];
            tmpNode->num=head->num;
            tmpNode->left=head->left;
            tmpNode->right=head->right;
            head->num=tmp.ss;
            head->left=tmpNode;
            head->right=&nodeheap[nodenum++];
            stk.pop();
            return update(head);  
    }
    }
    else{
    if(tmp.ss>=head->num){
        tmp.ss-=head->num;
        stk.pop();
        stk.push(tmp);
        if(tmp.ss>0){
            if(head->right==NULL) return update(head);
            else return fun(head->right);
        }
        else{
            stk.pop();
            if(head->left==NULL) return update(head);
            else return fun(head->left);
        }
    }
    else{
            head->num=head->num-tmp.ss;
            node *tmpNode=&nodeheap[nodenum++];
            tmpNode->num=head->num;
            tmpNode->left=head->left;
            tmpNode->right=head->right;
            head->num=tmp.ss;
            head->right=tmpNode;
            head->left=&nodeheap[nodenum++];
            stk.pop();
            return update(head);
    }    
    }
}

void free_memory(lstNode *head){
    if(head==NULL) return ;
    free_memory(head->next);
    free(head);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        sc(N);sc(Q);
        lstNode *lead=new lstNode;
        lead->type=0;
        lead->num=N;
        char c;
        ll ans=1;
        int C;
        node *head=&nodeheap[nodenum++];
        //head.val=0;
        while(Q--){
            getchar();
            //fflush(stdout);
            c='2';
            while(c!='!'&&c!='?')
                scanf("%c",&c);
            if(c=='!'){
                sc(C);
                add(C,lead);
               //fr(i,N) {pf(X[i]);sp;} br;
               lstNode *tmplead=lead;
               int count=0,ltp;
               ltp=tmplead->type;
               while(tmplead!=NULL){
                   count=0;
                do{
                    count+=tmplead->num;
                    tmplead=tmplead->next;
                }while(tmplead!=NULL&&tmplead->type==ltp);
                stk.push(ii(ltp,count));
                ltp=ltp^1;
                }
                ans+=fun(head);
            }                                                                                                                                   
            else{
               // fflush(stdout);
              // print(lead);

                pf1(ans);
                br;
            }
            
        }
        //free_memory(lead);
    }
    //assert((double)(c1-c0)/CLOCKS_PER_SEC<3);
return 0;
}