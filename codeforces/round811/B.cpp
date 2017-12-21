#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
bool quick(vi & a,int l,int r,int x){
    int rem=a[x];
    int count=0;
    for(int i=l;i<=r;i++){
        if(a[i]<a[x])
        count++;
    }
    if(l+count==x)
    return true;
    else
    return  false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
  int l,r,x;
    for(int t_i=0;t_i<m;t_i++){
        scanf("%d %d %d",&l,&r,&x);
        l--;x--;r--;
        if(quick(a,l,r,x))
            printf("Yes\n");
        else
        printf("No\n");
    }

    return 0;
}