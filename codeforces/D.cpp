#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ss second
#define ff first
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int a[100005]={0};
int depth[100005]={0};
int b[100005][2];
void dfs(int dep,int root,vector<vi >&AdjList){
    depth[root]=dep;
    for(int i=0;i<(int)AdjList[root].size();i++) dfs(dep,AdjList[root][i],AdjList);
}
int dfs1(int root,int ti,vector<vi > &AdjList){
    //cout<<root;
    b[root][0]=ti;
    if(AdjList[root].size()==0) {b[root][1]=ti; return b[root][1]+1;}
    ti++;
    for(int i=0;i<AdjList[root].size();i++)
        ti=dfs1(AdjList[root][i],ti,AdjList);
    b[root][1]=ti;
    return b[root][1]+1;
}
int out(int s,int f,int t){

}
int main(){
    int n,q;
    cin>>n>>q;
    a[0]=a[1]=-1;
    for(int i=2;i<=n;i++) cin>>a[i];
    vector<vi > AdjList(n+1);
    for(int i=2;i<=n;i++){
        AdjList[(a[i])].push_back(i);
    }
    
    dfs(0,1,AdjList);
    int end=dfs1(1,0,AdjList);
    for(int i=1;i<=n;i++) cout<<b[i][0]<<" "<<b[i][1]<<endl;
    //return 0;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,c,mx;
        cin>>a>>b>>c;
        mx=out(a,b,c);  //s,f,t;
        mx=max(mx,out(a,c,b));
        mx=max(mx,out(b,a,c));
        cout<<mx<<endl;
    }

    return 0;
}