#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
int k;

typedef struct{
    int memo[500]={0};
    int votes=0;
    int fin=0;
}grp;
vector<grp> grps(401);
inline void con(int r){
    int t=(r+1)/500;
    for(int i=0;i<t;i++)
        grps[i].votes++;
    r=r+1-(t-1)*500;
    for(int i=0;i<r;i++)
        grps[t].memo[i]++;
}
inline void decon(int l){
    if(l<0)
    return;
    int t=(l+1)/500;
    for(int i=0;i<t;i++)
    grps[i].votes--;
    for(int i=0;i<(l+1)%500;i++)
    grps[t].memo[i]--;
}
int qry(int r){
    if(r<0) return 0;
    int ans=0;
    int t=(r+1)/500;
    for(int i=0;i<t;i++)
    ans+=grps[i].fin;
    int v=grps[t].votes;
    for(int i=0;i<(r+1)%500;i++)
        if(grps[t].memo[i]+v>=k)
        ans++;
    return ans;
}

int main(){
    int n,q;
    cin>>n>>k>>q;
    int l,r;
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
       l--;r--;
        con(r);
        decon(l-1);
    }
    //return 0;
    //process
    int tmp;
    for(int i=0;i<401;i++){

        tmp=grps[i].votes;
        //cout<<tmp;
        for(int j=0;j<500;j++)
        if(grps[i].memo[j]+tmp>=k)
        grps[i].fin++;
    }
    while(q--){
        scanf("%d %d",&l,&r);
        l--;r--;
        printf("%d\n",qry(r)-qry(l-1));
    }
    return 0;
}