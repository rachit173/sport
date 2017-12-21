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
string s0="What are you doing at the end of the world? Are you busy? Will you save us?";
string s1="What are you doing while sending \""+s0+"\"? Are you busy? Will you send \""+s0+"\"?";
string z="\"? Are you busy? Will you send \"";
string y="\"?";
ll memo[100];
char rec(int n,ll k){
    if(n==0) {
        if(k<=s0.size()) return s0[k-1];
        else return '.';
    }
    if(n==1){
        if(k<=s1.size()) return s1[k-1];
        else return '.';
    }
    if(k<=34){
        return s1[k-1];
    }
    if(n<=64) {
        // ll tmp=memo[n-;
        ll tmp1 = k/34;
        if(tmp1>=n){
       char v=rec(0,k-n*34);
             if(v!='.'){
        return v;
        }   
        }
k=k-34;
    char c=rec(n-1,k);
    if(c!='.'){
        return c;
    }
    else{
        if(n>64) cout<<"error";
        ll tmp=memo[n-1];
        k=k-68*(tmp-1)-tmp*75;
        if(k<=32){
            return z[k-1];
        }
        else{
            k=k-32;
                    ll tmp1 = k/34;
        if(tmp1>=n){
       char v=rec(0,k-n*34);
             if(v!='.'){
        return v;
        }   
        }
            c = rec(n-1,k);
            if(c!='.') return c;
            else{
                if(n>64) cout<<"error";
                k=k-68*(tmp-1)-tmp*75;
                if(k<=2) return y[k-1];
                else return '.'; 
            }
        }
    }
    }
    else{
            k=k-34;
        return rec(n-1,k);
        // if(c!='.'){
        //     return c;
        // }
        // else{
        //     // if(n>64) cout<<"error";
        //     // ll tmp=((ll)1<<(ll)(n-1));
        //     // k=k-68*(tmp-1)-tmp*75;
        //     if(k<=32){
        //         return z[k-1];
        //     }
        //     else{
        //         k=k-32;
        //         c = rec(n-1,k);
        //         if(c!='.') return c;
        //         else{
        //             // if(n>64) cout<<"error";
        //             // k=k-68*(tmp-1)-tmp*75;
        //             if(k<=2) return y[k-1];
        //             else return '.'; 
        //         }
        //     }
        // }
    }
    
}
int main(){
int q;
cin>>q;
for(int i=1;i<=65;i++) memo[i] = ((ll)1<<(ll)i);
while(q--){
    ll n,k;
    
    sc1(n);sc1(k);
    if(n>=63){

    }
    // cout<<s0<<" "<<s0.size()<<endl;
    // cout<<s1<<" "<<s1.size()<<endl;
    cout<<rec(n,k);
}   
return 0;
}
