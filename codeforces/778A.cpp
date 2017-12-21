#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
bool b[200000];
int n;
bool check(string &s,string &q){
    int l=0;
    for(int i=0;i<n;i++)
        if(s[i]==q[l]&&b[i]) l++;
    if(l>=q.size()) return true;
    return false;
}
int bin(string &s,string &q,int l,int r,vi &a){
    //cout<<l<<" "<<r;
    if(r-l<2){
        memset(b,true,sizeof(b));
        for(int i=0;i<r;i++)
            b[(a[i]-1)]=false;
            if(r<n&&check(s,q)) return r;
            else return l;
    }
    int mid=(l+r)/2;
    string t;
    memset(b,true,sizeof(b));
    for(int i=0;i<mid;i++)
        b[(a[i]-1)]=false;
        if(check(s,q)) return bin(s,q,mid,r,a);
    return bin(s,q,l,mid,a);
}
int main(){
    string s;
    string q;
    cin>>s>>q;
    n=s.size();
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=bin(s,q,0,n,a);
    cout<<ans;
    return 0;
}