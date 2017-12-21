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
#define pb push_back
#define ff first
#define ss second
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
struct datapt {
    string date;
    double open_price;
    double high_price;
    double low_price;
    double close_price;
    double shares_traded;
    double turnover_in_cr;
};
class Stock 
{
public:
    
private:
    int days;
    vector<datapt> vec;
    void input_data_from_ssv(string s){

    }
}
int main(){
 freopen("parsed_data.ssv","r",stdin);
 string s;
 vector<datapt> vec;
 datapt a;
 char token[80];
 int count = 0;
 while(scanf("%s",token)>0){
     a.date=token;
     scanf("%lf %lf %lf %lf %lf %lf",&a.open_price,&a.high_price,&a.low_price,&a.close_price,
                                        &a.shares_traded,&a.turnover_in_cr);
                                            count++;
}
pf(count);
return 0;
}