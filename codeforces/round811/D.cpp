#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii; //pair of int;pair<int,int>
typedef vector<int> vi; //vector of int
typedef vector<ii> vii; //vector of pair<int,int>
#define INF 1000000000
int n,m;
char U,D,L,R;
bool visit[101][101];
bool recursive(vector<vi> & graph,int x,int y,stack<char,vector<char> > &s){
    //string tmp;
        if(x>=n||y>=m||x<0||y<0||graph[x][y]==1)
    return false;
    if(graph[x][y]==2)
    return true;

    if(visit[x][y]==true)
    return false;
    visit[x][y]=true;
    //left
    //cout<<x<<" "<<y<<endl;
    //return true;
    if(recursive(graph,x,y-1,s)){
        s.push('L');
        return true;
    }
    //right
    if(recursive(graph,x,y+1,s)){
        s.push('R');
        return true;
    }
    //up
    if(recursive(graph,x-1,y,s)){
        s.push('U');
        return true;
    }
    //down
    if(recursive(graph,x+1,y,s)){
        s.push('D');
        return true;
    }
    return false;
}
int main(){
    
    cin>>n>>m;
    char grid[n][m+1];
    
    U='U';
    D='D';
    L='L';
    R='R';
    for(int i=0;i<n;i++)
    cin>>grid[i];
    fflush(stdout);
    int x,y;
    if(grid[1][2]=='.'){
        printf("%c\n",R);
        fflush(stdout);
        cin>>x>>y;
        if(x==1&&y==1)
        {
            L='R';
            R='L';
        }
        else{
            printf("%c\n",L);
            fflush(stdout);
            cin>>x>>y;
        }
        while(grid[x-1][y-1+1]!='*'&&y<m&&grid[x-1+1][y-1]=='*'){
            printf("%c\n",R);
            fflush(stdout);
            cin>>x>>y;
        }
        printf("%c\n",D);
        fflush(stdout);
        cin>>x>>y;
        if(x==1){
            D='U';
            U='D';
        }
    }
    else{
                printf("%c\n",D);
        fflush(stdout);
        cin>>x>>y;
        if(x==1){
            D='U';
            U='D';
        }
        else{
            printf("%c\n",U);
            fflush(stdout);
            cin>>x>>y;
        }
        while(grid[x-1+1][y-1]!='*'&&x<n&&grid[x-1][y-1+1]=='*'){
            printf("%c\n",D);
            fflush(stdout);
            cin>>x>>y;
        }
                printf("%c\n",R);
        fflush(stdout);
        cin>>x>>y;
        if(y==1)
        {
            L='R';
            R='L';
        }
    }
    fflush(stdout);
    vector<vi> graph(n,vi (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*')
            graph[i][j]=1;
            if(grid[i][j]=='F')
            graph[i][j]=2;
        }
    }
    stack <char,vector<char> > s;
    memset(visit,false,sizeof(visit));
    //return 0;
    bool xyz=recursive(graph,x-1,y-1,s);
    int tmpx,tmpy;
    while(!s.empty()){
        if(s.top()=='L')
        printf("%c\n",L);
        if(s.top()=='R')
        printf("%c\n",R);
        if(s.top()=='U')
        printf("%c\n",U);
        if(s.top()=='D')
        printf("%c\n",D);
    fflush(stdout);
    cin>>tmpx>>tmpy;
    s.pop();
    }
    cout<<"F"<<endl;
    return 0;
}