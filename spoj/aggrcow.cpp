#include<bits/stdc++.h>
//in this kind of optimisation problems one must
//calculate the complexity of optimisation and 
//which in this case was O(N)
//but the complexity of  finding the optimum value was log(max(x)-min(x))
using namespace std;
typedef vector<int> vi;
int a[100005];
int N,C;
bool check(int test){
    int c=C;
    int t=a[0]+test;
    c--;
    for(int i=1;i<N&&c>0;i++){
        if(a[i]>=t){
            c--;
            t=a[i]+test;
        }
    }
    if(c==0)
    return true;
    return false;
}
int bs(int start,int end){
    if(start==end)
        return start;
    int test=(start+end+1)/2;
    if(check(test))
        return bs(test,end);
    return bs(start,test-1);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>C;
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
        sort(a,a+N);

        int m=(a[N-1]-a[0]+2)/(C-1);
        int ans=bs(0,m);
        cout<<ans<<endl;
    }
    return 0;
}