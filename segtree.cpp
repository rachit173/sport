#include<bits/stdc++.h>
using namespace std;
#define oo 1000000000
int a[100000];
int b[100000];
int seg[400000];
int seg1[400000][2];
int n;
int bin(int L,int R,int index){
 // cout<<L<<" "<<R<<" "<<index<<endl;
  if(R-L<2) {
    seg[index]=a[L];
    return seg[index];
  }
  int mid=(L+R)/2;
  seg[index]=max(bin(L,mid,2*index),bin(mid,R,2*index+1));
    int left_max=a[mid-1];
    int right_max=a[mid];
    int left_tmp=a[mid-1],right_tmp=a[mid];
    for(int i=mid+1;i<R;i++) right_tmp+=a[i],right_max=max(right_max,right_tmp);
    seg1[2*index+1][0]=right_max;
    for(int i=mid-2;i>=L;i--) left_tmp+=a[i],left_max=max(left_max,left_tmp);
    seg1[2*index][1]=left_max;
  seg[index]=max(left_max+right_max,seg[index]);
  return seg[index];
}
int fun(int side,int L,int mid,){
  
}
int search(int L,int R,int st,int en,int index){
  //cout<<L<<" "<<R<<" "<<st<<" "<<en<<" "<<index<<endl;
  int mid=(st+en)/2;
  if(L>=R) return -oo;
  if(L<=st&&en<=R) return seg[index];
  return max();
}
int main(){
  cin>>n;
  memset(a,-oo,sizeof(a));
  memset(seg,-oo,sizeof(seg));
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  int mx=bin(0,n,1);
  int q;
  cin>>q;
  int l,r;
  //for(int i=0;i<15;i++) cout<<seg[i]<<" ";
  //cout<<endl;
  while(q--){
  scanf("%d %d",&l,&r);
  l--,r--;
  printf("%d\n",search(l,r+1,0,n,1));
  }
  return 0;
}
