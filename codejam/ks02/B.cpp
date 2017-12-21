#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
char grid[105][105];
int n,m;
int fun1(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        if(grid[i][j]=='B') return i;
    }
    return n;
}
int fun2(){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++)
        if(grid[i][j]=='B') return i;
    }
    return n;
}
int fun3(){
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++)
        if(grid[i][j]=='B') return j;
    }
    return m;
}
int fun4(){
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++)
        if(grid[i][j]=='B') return j;
    }
    return m;
}
int main() {
	// your code goes here
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>grid[i];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        if(grid[i][j]=='B') count++;
    }
    int up,down,left,right;
    up=fun1();
    down=fun2();
    left=fun3();
    right=fun4();
    int x=right-left+1;
    int y=down-up+1;
    if(up==n) y=0;
    if(left==m) x=0;
    if(count==0) cout<<"1\n";
    else{
        if(x==y) cout<<x*x-count<<endl;
        else{
            if(x>y){
                int t=x-y;
                if(up-t>=0||down+t<n) cout<<x*x-count<<endl;
                else cout<<"-1";
            }
            else{
                int t=y-x;
                if(left-t>=0||right+t<m) cout<<y*y-count<<endl;
                else cout<<"-1";
            }
        }
    }
	return 0;
}
