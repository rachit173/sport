#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int fun(vector<vi > &AdjList,vi &color){
        for(int i=0;i<n-1;i++){
        for(int j=1;j<AdjList[i].size();j++){
            if(color[(AdjList[i][j])]!=color[(AdjList[i][j-1])])
            return i;
        }
    }
    return -1
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
    vi color[n];
    for(int i=0;i<n;i++) cin>>color[i];
    int flips=0;
    for(int i=0;i<n-1;i++){_}
    //int root=-1;
    int root=fun(AdjList,color);
    for(int i=0;i<AdjList[root];i++){

    }
    return 0;
}