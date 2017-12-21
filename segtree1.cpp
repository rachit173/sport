#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll oo=1000000000;
ll a[100000];
ll b[100000];
ll seg[400000];
ll seg1[400000];
ll seg2[400000];
ll n;
ll bin(int L,int R,int index){
 // cout<<L<<" "<<R<<" "<<index<<endl;
  if(R-L<2) {
    seg[index]=a[L];
    return seg[index];
  }
  ll mid=(L+R)/2;
  seg[index]=max(bin(L,mid,2*index),bin(mid,R,2*index+1));
    ll left_max=a[mid-1];
    ll right_max=a[mid];
    ll left_tmp=a[mid-1],right_tmp=a[mid];
    for(int i=mid+1;i<R;i++) right_tmp+=a[i],right_max=max(right_max,right_tmp);
    for(int i=mid-2;i>=L;i--) left_tmp+=a[i],left_max=max(left_max,left_tmp);  
  seg[index]=max(left_max+right_max,seg[index]);
  return seg[index];
}
ll bin1(int L,int R,int index){
 // cout<<L<<" "<<R<<" "<<index<<endl;
  if(R-L<2) {
    seg1[index]=b[L];
    return seg1[index];
  }
  ll mid=(L+R)/2;
  seg1[index]=max(bin1(L,mid,2*index),bin1(mid,R,2*index+1));
  return seg1[index];
}
ll bin2(int L,int R,int index){
 // cout<<L<<" "<<R<<" "<<index<<endl;
  if(R-L<2) {
    seg2[index]=b[L];
    return seg2[index];
  }
  ll mid=(L+R)/2;
  seg2[index]=min(bin2(L,mid,2*index),bin2(mid,R,2*index+1));
  return seg2[index];
}
ll search1(int L,int R,ll st,ll en,int index){
  //cout<<L<<" "<<R<<" "<<st<<" "<<en<<" "<<index<<endl;
  ll mid=(st+en)/2;
  if(L==st&&R==en) return seg1[index];
  if(L<mid&&R<=mid) return search1(L,R,st,mid,2*index);
  else if(mid<=L&&mid<R) return search1(L,R,mid,en,2*index+1);
  else return max(search1(L,mid,st,mid,2*index),search1(mid,R,mid,en,2*index+1));
}
ll search2(int L,int R,ll st,ll en,int index){
  //cout<<L<<" "<<R<<" "<<st<<" "<<en<<" "<<index<<endl;
  ll mid=(st+en)/2;
  if(L==st&&R==en) return seg2[index];
  if(L<mid&&R<=mid) return search2(L,R,st,mid,2*index);
  else if(mid<=L&&mid<R) return search2(L,R,mid,en,2*index+1);
  else return min(search2(L,mid,st,mid,2*index),search2(mid,R,mid,en,2*index+1));
}
ll search(int L,int R,ll st,ll en,int index){
  //cout<<L<<" "<<R<<" "<<st<<" "<<en<<" "<<index<<endl;
  ll mid=(st+en)/2;
  if(L==st&&R==en) return seg[index];
  if(L<mid&&R<=mid) return search(L,R,st,mid,2*index);
  else if(mid<=L&&mid<R) return search(L,R,mid,en,2*index+1);
  else {
    // ll left_max=a[mid-1];
    // ll right_max=a[mid];
    // ll left_tmp=a[mid-1],right_tmp=a[mid];
    // for(int i=mid+1;i<R;i++) right_tmp+=a[i],right_max=max(right_max,right_tmp);
    // for(int i=mid-2;i>=L;i--) left_tmp+=a[i],left_max=max(left_max,left_tmp);   
    //cout<<L<<" "<<R<<endl;
    //cout<<search1(mid,R,mid,en,2*index+1)<<" "<<search2(L,mid,st,mid,2*index)<<endl; 
    ll tmp=search1(mid,R,mid,en,2*index+1)-min(search2(L,mid,st,mid,2*index),L>=1?b[L-1]:0);
    return max(max(search(L,mid,st,mid,2*index),search(mid,R,mid,en,2*index+1)),tmp);
  }
}

int main(){
  cin>>n;
  memset(a,-oo,sizeof(a));
  memset(seg,-oo,sizeof(seg));
  memset(seg1,-oo,sizeof(seg1));
  memset(seg2,oo,sizeof(seg2));
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  b[0]=a[0];
  for(int i=1;i<n;i++) b[i]=b[i-1]+a[i];
  ll mx=bin(0,n,1);
  mx=bin1(0,n,1);
  ll mn=bin2(0,n,1);
  ll q;
  cin>>q;
  int l,r;
  //for(int i=0;i<15;i++) cout<<seg[i]<<" ";
  //cout<<endl;
  while(q--){
  scanf("%d %d",&l,&r);
  l--,r--;
  printf("%lld\n",search(l,r+1,0,n,1));
  }
  return 0;
}
