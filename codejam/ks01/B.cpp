#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
bool grid[5000][5000];
int R,C;
int fun1(vii &a,int u,int v){
    int x=R-u;
    //int i=lower_bound(a.begin(),a.end(),ii(u,v))-a.begin();
    for(int i=0;i<(int)a.size();i++)
        if(a[i].first>=u&&a[i].second>=v&&(a[i].first-u)>=(a[i].second-v)&&(a[i].first-u)<x)
            x=a[i].first-u;
    return x;
}
int fun2(vii &a,int u,int v){
    int y=C-v;
    //int i=upper_bound(a.begin(),a.end(),ii(u,v))-a.begin();
    for(int i=0;i<(int)a.size();i++)
        if((a[i].first-u)<=(a[i].second-v)&&(a[i].second-v)<y)
            y=a[i].second-v;
    return y;
}
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        int K;
        cin>>R>>C>>K;
        memset(grid,false,sizeof(grid));
        vii a(K+1);
        vii b(K+1);
        int u,v;
        for(int i=0;i<K;i++){
            scanf("%d %d",&u,&v);
            a[i]=ii(u,v);
            b[i]=ii(v,u);
            grid[u][v]=true;
        }
        a[K]=ii(R,C);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        //vii::iterator tmp1,tmp2;
        ll ans=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==true) continue;
                ans+=(ll)min(fun1(a,i,j),fun2(a,i,j));
            }
        }
        printf("Case #%d: %lld\n",t_i+1,ans);
    } 
    return 0;
}