#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
    string t,p;
    cin>>t>>p;
    int n=t.size();
    vi a(t.size());
    vi b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]=i+1;
    }

    return 0;
}