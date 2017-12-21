#include<bits/stdc++.h>
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef tup struct{
    ll value;
    int num;
    int x;
}
typedef vector<tup> vll;
vll memo(500000);
ll dp(ll R,vi &a){
    if(R<0)
    return 0;
    if(memo[R].first!=-1)
    return memo[R];
    ll tmp=dp(R-1);
    int x=memo[R-1].x;
    int num=memo[R-1].num;
    if(x<=x^a[R]){
    memo[R].value=dp(R-1)+num+1;
    memo[R].num=num+1;
    memo[R].x=x^R;
    }
    else{
        memo[R].value]
    }
    memo[R].num
}
int main(){
    ll n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        memo[i].value=-1;
        memo[i].num=-1;
        memo[i].x=-1;
    }
    //memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int q;
    cin>>q;
    ll ansprev=0;
    ll L,R;
    for(int i=0;i<q;i++)
    {   
        scanf("%d %d",&L,&R);
        L=(L+ansprev)%n;
        R=(R+ansprev)%n;
        ansprev=dp(R)-dp(L-1);
        printf("%lld\n",ansprev);
    }

    return 0;
}