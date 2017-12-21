#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define ll long long int 
ll a[20];
ll b[20];
ll c[20];
void recursion(int n){
if(n==13)
return;
a[n]=1+a[n-1]+c[n-1];
b[n]=a[n-1]+b[n-1];
c[n]=c[n-1]+b[n-1];
recursion(n+1);
}
void print(int N,char win,char loser,char inter){
    if(N==1){
        if(win<loser)
    printf("%c%c",win,loser);
    else
    printf("%c%c",loser,win);
    return;
    }
    if(win<inter){
    if(win<loser){
    print(N-1,win,loser,inter);
    print(N-1,loser,inter,win);
    }
    else{
        print(N-1,loser,inter,win);
        print(N-1,win,loser,inter);
    }
    }
    else{
                print(N-1,loser,inter,win);
        print(N-1,win,loser,inter);
    }
}
int main(){
    a[0]=1;b[0]=0;c[0]=0;
    recursion(1);
    int T;
    cin>>T;
   
    for(int t_i=0;t_i<T;t_i++)
    {
        int N,R,P,S;
        scanf("%d %d %d %d",&N,&R,&P,&S);
        int game[3];
        game[0]=a[N]-a[N-1];
        game[1]=b[N]-b[N-1];
        game[2]=c[N]-c[N-1];
        printf("Case #%d: ",t_i+1);
        if(game[0]==P&&game[1]==R&&game[2]==S){
            print(N,'P','R','S');
        }
        //else if(game[0]==P&&game[1]==S&&game[2]==R){
          //  print(N,'P','S','R');
        //}
        //else if(game[0]==R&&game[1]==P&&game[2]==S){
        //     print(N,'R','P','S');
        // }
        else if(game[0]==R&&game[1]==S&&game[2]==P){
            print(N,'R','S','P');
        }
        else if(game[0]==S&&game[1]==P&&game[2]==R){
            print(N,'S','P','R');
        }
        else
        printf("IMPOSSIBLE");
        printf("\n");
    }
    return 0;
}