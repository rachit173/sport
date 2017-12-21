#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll a[100000];
ll b[100000];
ll seg[500000];
int binsearch(vi& vec,int start,int end,int pos){
    int mid=start+(end-start)/2;
//    cout<<mid<<" "<<vec[mid]<<" 2 "<<pos<<endl;
    if(end-start<2) return vec[start];
    if(end-start==2){
        if(vec[start]>=pos) return vec[start];
        return vec[end-1];
    }
    if(vec[mid]==pos) return pos; 
    else if(vec[mid]< pos)return binsearch(vec,mid+1,end,pos);
    else return binsearch(vec,start,mid+1,pos);
}
int main(){
    int n;
    cin>>n;
    vi vec;
    vec.push_back(0);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);
    ll max_ending_here=b[0];
    a[0]=b[0];
    for(int i=1;i<n;i++){
        if(b[i]+a[i-1]<=b[i]){
            a[i]=b[i];
            vec.push_back(i);
        }
        else a[i]=b[i]+a[i-1];
    }
    int q;
    vec.push_back(n);
//    for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
    scanf("%d",&q);
    int l,r;
    int tmp1,tmp2;
    while(q--){
        scanf("%d%d",&l,&r);
        l--;r--;
  //      cout<<l<<endl;
        int index;
        index=binsearch(vec,0,vec.size(),l);
        if(index>r){
          tmp1=
          search()
        }
        cout<<index<<endl;
    }

    
    return 0;
}
