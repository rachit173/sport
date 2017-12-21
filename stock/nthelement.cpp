//this program also contains the code for randomised sort
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
inline void swap(vi & a,int start,int end){
    int tp=a[start];
    a[start]=a[end];
    a[end]=tp;
}
int randomisedPartition(vi &a,int l,int r){
    int t=rand()%(r-l+1)+l;
    int pivot=a[t];
    swap(a,t,r);
//cout<<pivot<<" ";
    int i=l;
    for(int j=l;j<r;j++){
        if(a[j]<=pivot){
        swap(a,i,j);
        i++;}
    }
    swap(a,i,r);
    return i;
}
int nthelement(vi &a,int l,int r,int k){
    int q=randomisedPartition(a,l,r);
//cout<<q<<endl;
    for(int i=0;i<a.size();i++)
  //  cout<<a[i]<<" ";
    //cout<<endl;
    if(q+1==k) return a[q];
    else if(k<q+1)
            return nthelement(a,l,q-1,k);
    else 
            return nthelement(a,q+1,r,k);
}
int main(){
    int T=10000;
    while(T--){
        srand(time(NULL));
    int n,k;
    n=rand()%(10000+T)+1;
    k=rand()%n+1;
    vi a(n);
    vi b(n);
    for(int i=0;i<n;i++)
        a[i]=rand()%(int(1e9)+7);
    b=a;
    nth_element(b.begin(),b.begin()+k-1,b.end());
    if(nthelement(a,0,n-1,k)!=b[k-1])
    {
        cout<<"Failed"<<endl;
        return 0;
    }
    }
    cout<<"Passed"<<endl;
    return 0;
}