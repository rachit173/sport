#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
bool check(ll N,int t){
    while(N>1){
        if((N-1)%t==0)
            N=(N-1)/t;
            else return false;
    }
    return true;
}
int main(){
    int T;
    cin>>T;
    ll N;
    for(int t_i=0;t_i<T;t_i++){
        cin>>N;
        vi a;
        ll lim=1000000;
        if(N<lim) lim=N;
        for(int i=2;i<(int)lim;i++)
            if((N-1)%i==0) a.push_back(i);
        ll ans=N-1;
        ll tmp=sqrt(1+4*(N-1));
        //cout<<tmp<<endl;
        tmp=(tmp-1)/2;
        if(tmp*tmp+tmp+1==N&&tmp>1) ans=tmp;
        for(int i=0;i<(int)a.size();i++){
            if(check(N,a[i])){
                ans=a[i];
                break;
            }
        }
        cout<<"Case #"<<t_i+1<<": "<<ans<<endl;
    }
}