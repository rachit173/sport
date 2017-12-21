#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vi > memo[2];
bool dfs(int root,vector<vi > &AdjList,vi &color){
    int t;
    for(int i=0;i<AdjList[root].size();i++){
        t=AdjList[root][i];
        if(color[t]==-1){
            color[t]=color[root]^1;
            memo[color[t]].push_back(t+1);
            if(dfs(t,AdjList,color)) continue;
            else return false;
        }
        else{
            if(color[t]==color[root])
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<vi > AdjList(n-1);
    int u,v,c;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    vi color(N,-1);
    int root=0;
    color[root]=0;
    memoo[0].push_back(1);
    if(dfs(root,AdjList,color))
    {
        cout<<memo[0].size()<<endl;
        for(int i=0;i<memo[0].size;i++)
        cout<<memo[0][i]<<" ";
        cout<<endl;
                cout<<memo[1].size()<<endl;
        for(int i=0;i<memo[1].size;i++)
        cout<<memo[1][i]<<" ";
        cout<<endl;
        
    }
    else{
        cout<<"-1";
    }
    return 0;
} 
