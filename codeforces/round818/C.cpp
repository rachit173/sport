#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
int n,m;
int g[101][101];
void print(int opt,int num,int k){
    if(opt==0){
            for(int i=0;i<k;i++)
        printf("row %d\n",num);
    }
    else{
        for(int i=0;i<k;i++)
        printf("col %d\n",num);
    } 
}
int fun(int t){
    int g1[n][m];
    int ans=0;
    ans+=(g[0][0]);
    memset(g1,0,sizeof(g1));
    for(int i=0;i<m;i++)
        g1[0][i]+=t;
    for(int i=0;i<n;i++)
        g1[i][0]+=(g[0][0]-t);
        int tmp;
    for(int i=1;i<n;i++)
    {
        tmp=abs(g[i][0]-g1[i][0]);
        ans+=tmp;
        for(int j=0;j<m;j++)
            g1[i][j]+=tmp;
    }
    for(int i=1;i<m;i++){
        tmp=abs(g[0][i]-g1[0][i]);
        ans+=tmp;
        for(int j=0;j<n;j++)
            g1[j][i]+=tmp;
    }

        for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(g[i][j]!=g1[i][j]) return -1;
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    scanf("%d",&g[i][j]);
    }
    }
    int t1=g[0][0];
    vii v;
    int tmp;
//    cout<<t1<<endl;
    for(int i=0;i<=t1;i++){
        if((tmp=fun(i))!=-1)
            v.push_back(ii(tmp,i));
    }
    if(v.size()==0)
        cout<<"-1\n";
    else{
        int mi=v[0].first;
        int a,b;
        for(int i=0;i<(int)v.size();i++){
            if(v[i].first<=mi){
                mi=v[i].first;
                a=v[i].second;
                b=t1-a;
            }
        }
        cout<<mi<<endl;
        print(0,1,a);
        print(1,1,b);
        for(int i=1;i<m;i++)
            print(1,i+1,g[0][i]-a);
        for(int i=1;i<n;i++)
        print(0,i+1,g[i][0]-b);
    }
    return 0;
}