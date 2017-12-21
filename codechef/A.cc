#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d",a)
#define sc1(a) scanf("%lld",&a)
#define pf1(a) printf("%lld",a)
#define sc2(a) scanf("%d %d",&a.first,&a.second)
#define br printf("\n")
#define sp printf(" ")
#define ll long long int
#define ff first
#define ss second
#define pb(h_) push_back(h_)
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,st,n) for(int i=st;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
#define mod 1000000007
#define mod1 1000000009
#define oo 1000000000
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int sieve[100005];
vl pms;
ll powmod(ll b,ll x,ll m){
    ll ret = 1;
    ll tmp = b;
    while(x>0){
        if(x%2==1) ret = (ret*tmp)%m;
        x= x/2;
        tmp = (tmp*tmp)%m;
    }
    return ret;
}
int main(){
    int T;
    cin>>T;
    RESET(sieve,0);
    sieve[0] = sieve[1] =1;
    for(int i=2;i<100000;i++){
        if(sieve[i]==0){
            for(int j = 2*i;j<100000;j+=i)
                sieve[j] = 1;
        }
    }
    f(i,100000) if(sieve[i]==0) pms.pb(i);
    // cout<<pms.size()<<endl;
    // f(i,10) cout<<pms[i]<<" ";
    // cout<<endl;
    f(t_i,T){
        ll N;
        N = pms[10*959+3];
        cout<<N<<endl;
        try{
        ll tmp = N-1;
        vii ans;
        f(i,pms.size()){
            if(tmp%pms[i]==0&&pms[i]!=N-1){
                    // cout<<pms[i]<<endl;
                ii ret;
                ret.ff = pms[i];
                ret.ss = 0;
                while(tmp%pms[i]==0){
                    tmp/=pms[i];
                    ret.ss++;
                }
                ans.pb(ret);
            }
    }
        if(tmp>1){
            ans.pb(ii(tmp,1));
        }
        ans.pb(ii(1,1));
        int d=0;
        tmp = N-1;
        while(tmp>0){
            tmp/=10;
            d++;
        }
        int p;
        ll tmp1;
        ii fin = ii(N-1,1);
        vl haha;
        sort(ans.begin(),ans.end());
        f(i,ans.size()){
            f(j,ans[i].ss){
                haha.pb(ans[i].ff);
            }
        }
        set<ll> baba;
        baba.insert(1);
        f(i,haha.size()){
            vl tmp;
            for(auto e:baba)
                tmp.pb(e*haha[i]);
            for(auto e:tmp)
                baba.insert(e);
        }
        // vi caca(baba);
        for(auto p:baba){
            // p = ans[i].ff;
            // cout<<p/<<" ";
            if(p>=d-1){
                tmp1 = powmod(10,p,N);
                // cout<<p<<" "<<tmp1;
                if(tmp1==1){
                    if(p<fin.ff){
                        fin = ii(p,1);
                    }
                }
                else if(tmp1==N-1){
                    if(p<fin.ff){
                        fin = ii(p,-1);
                    }
                }
            }
        }
        if(fin.ss==1){
            printf("Case %d: %lld-sum\n",t_i+1,fin.ff);
        }
        else{
            printf("Case %d: %lld-altersum\n",t_i+1,fin.ff);
        }
        }
        catch(exception &e){
            cout<<N<<endl;
        }
    }
    return 0;
}
