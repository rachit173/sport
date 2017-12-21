//by rachit
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
int main(){
    char c[10];
    cin>>c;
    char c1[3];
    c1[0]=c[0];
    c1[1]=c[1];
    c1[2]='\0';
    char c2[3];
    c2[0]=c[3];
    c2[1]=c[4];
    c2[3]='\0';
    int t=atoi(c1)*60+atoi(c2);
    int b[16]={70,140,210,280,350,601,671,741,811,881,951,1202,1272,1342,1412,1440};
    vi v;
    for(int i=0;i<16;i++)
    if(b[i]>=t) v.push_back(b[i]-t);
    int mi=100000;
    for(int i=0;i<v.size();i++)
        mi=min(mi,v[i]);
    if(t==0)
    cout<<"0"<<endl;
    else
    cout<<mi<<endl;
    return 0;
}