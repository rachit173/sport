#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll memo[101][101];
int h,w;
int grid[101][101];
ll dp(int x,int y){
    if(x>=h)
        return 0;
    if(y>=w||y<0) return 0;
    if(memo[x][y]!=-1) return memo[x][y];
    memo[x][y]=grid[x][y]+max(max(dp(x+1,y+1),dp(x+1,y-1)),dp(x+1,y));
    return memo[x][y];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(memo,-1,sizeof(memo));
        cin>>h>>w;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            scanf("%d",&grid[i][j]);
        ll ans=-1;
        for(int i=0;i<w;i++)
            ans=max(ans,dp(0,i));
        printf("%lld\n",ans);
    }
    return 0;
}