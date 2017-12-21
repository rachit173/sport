#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define ll  long long int
int main(){
    int N;
    int ans=0,t;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&t);
        ans^=t;
    }
     cout<<ans<<endl;
    return 0;
}