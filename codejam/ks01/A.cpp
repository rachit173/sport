#include<bits/stdc++.h>
using namespace std;
#define ll long long int
char c[105];
ll cnt(ll R){
    if(R<=0) return 0;
    ll sz=strlen(c);
    ll b=0;
    for(int i=0;i<sz;i++)
    if(c[i]=='B') b++;
    ll ans=(R/sz)*b;
    for(int i=0;i<R%sz;i++)
        if(c[i]=='B') ans++;
    return ans;

}
int main(){
    int T;
    cin>>T;
    for(int t_i=0;t_i<T;t_i++){
        
        scanf("%s",c);
        ll L,R;
        cin>>L>>R;
        printf("Case #%d: %lld\n",t_i+1,cnt(R)-cnt(L-1));
    }   
    return 0;
}