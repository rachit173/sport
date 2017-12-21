#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define ll long long int
int main(){
    int n;
    cin>>n;
    int grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&grid[i][j]);
    }
    int t;
    bool opt=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            opt=false;
            if(grid[i][j]==1) continue;
            for(int k=0;k<n&&opt==false;k++){
                t=grid[i][j]-grid[i][k];
                for(int l=0;l<n;l++)
                if(grid[l][j]==t) opt=true;
            }
            if(opt==false){
                cout<<"No\n"; return 0;
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}