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
#define MAXN 500005
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll a[MAXN];
ll seg1[MAXN];
ll seg2[MAXN];
ll seg3[MAXN];
ll seg4[MAXN];
//segment tree for Range Maximum Query 
void update1(int index,int l,int r,int val,int base){
    if(r<=l){
        seg1[base] =val;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update1(index,l,mid-1,val,2*base);
        seg1[base] = max(seg1[2*base],seg1[2*base+1]);
        // cout<<index<<" "<<l<<" "<<r<<" "<<base<<" "<<seg1[base]<<endl;
    }else{
        update1(index,mid,r,val,2*base+1);
        seg1[base] = max(seg1[2*base],seg1[2*base+1]);
        // cout<<index<<" "<<l<<" "<<r<<" "<<base<<" "<<seg1[base]<<endl;
    }
}
ll search1(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg1[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search1(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search1(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg1[base];
    return max(search1(start,mid-1,l,mid-1,2*base),
                search1(mid,end,mid,r,2*base+1));
}
//segment tree for range sum query 
void update2(int index,int l,int r,int val,int base){
    if(r<=l){
        seg2[base] =val;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update2(index,l,mid-1,val,2*base);
        seg2[base] = min(seg2[2*base],seg2[2*base+1]);
    }else{
        update2(index,mid,r,val,2*base+1);
        seg2[base] = min(seg2[2*base],seg2[2*base+1]);
    }
}
ll search2(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg2[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search2(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search2(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg2[base];
    return min(search2(start,mid-1,l,mid-1,2*base),
                search2(mid,end,mid,r,2*base+1));
}
//segment tree for finding if a range is increasing
void update3(int index,int l,int r,int val,int base){
    if(r<=l){
        seg3[base] =1;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update3(index,l,mid-1,val,2*base);
        if(seg3[2*base]&&seg3[2*base+1]&&a[mid-1]<=a[mid]) seg3[base]=1;
        else seg3[base]=0;
    }else{
        update3(index,mid,r,val,2*base+1);
        if(seg3[2*base]&&seg3[2*base+1]&&a[mid-1]<=a[mid]) seg3[base]=1;
        else seg3[base]=0;
    }
}
ll search3(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg3[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search3(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search3(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg3[base];
    if(search3(start,mid-1,l,mid-1,2*base)&&search3(mid,end,mid,r,2*base+1)&&a[mid-1]<=a[mid]) return 1;
    return 0;
}
//segment tree for finding if range is decreasing 
void update4(int index,int l,int r,int val,int base){
    if(r<=l){
        seg4[base] =1;
        return ;
    }
    int mid = l+(r-l+1)/2;
    if(index<mid){
        update4(index,l,mid-1,val,2*base);
        if(seg4[2*base]&&seg4[2*base+1]&&a[mid-1]>=a[mid]) seg4[base]=1;
        else seg4[base]=0;
    }else{
        update4(index,mid,r,val,2*base+1);
        if(seg4[2*base]&&seg4[2*base+1]&&a[mid-1]>=a[mid]) seg4[base]=1;
        else seg4[base]=0;
    }
}
ll search4(int start,int end,int l,int r,int base){
    if(r<=l){
        return seg4[base];
    }
    int mid = l+(r-l+1)/2;
    if(end<mid){
        return search4(start,end,l,mid-1,2*base);
    }
    else if(start>=mid){
        return search4(start,end,mid,r,2*base+1);
    }
    else if(start==l&&end==r) return seg4[base];
    if(search4(start,mid-1,l,mid-1,2*base)&&search4(mid,end,mid,r,2*base+1)&&a[mid-1]>=a[mid]) return 1;
    return 0;
}
int main(){
int N,M;
cin>>N;
// int b[N+1];
// RESET(seg1,0);
// RESET(seg2,0);
for(int i=0;i<N;i++){
    sc1(a[i]);
    // b[i]--;    // update3(i,0,N-1,a[i],1);
    // update4(i,0,N-1,a[i],1);
}
// f(i,N){
//     a[b[i]] = i;
//     update1(b[i],0,N-1,i,1);
//     update2(b[i],0,N-1,i,1);
// }
// f(i,15){pf1(seg1[i]);sp;}
// ll z[N+1];
// z[N-1] = a[N-1];
// for(int i=N-2;i>=0;i--){
//     z[i] = min(z[i+1],a[i]);
// }
// int mx=-2;
// int ans=0;
// for(int i=0;i<N;i++){
//     int tmp;
//     int c = a[i];
//     cout<<c<<endl;
//     int d;
//     if(i==N-1) d = N;
//     else {d = z[i+1];}//search2(i+1,N-1,0,N-1,1);
//     cout<<d<<endl;
//     if(d<c) {
//         tmp=0;
//     }
//     else{
//         tmp = d-c-2;
//     }
//     cout<<"tmp"<<tmp<<endl;
//     if(tmp>mx){
//         mx=tmp;
//         ans = i+1;
//     }
// }
// cout<<ans<<endl;
int b[N+1][2];
b[0][0]=a[0];
b[0][1]=-1;
int ans[N+1]={0};
for(int i=1;i<N;i++){
    int tmp = b[i-1][0]; 
    if(a[i]>tmp){
        b[i][0] = a[i];
        b[i][1] = tmp;
    } 
    else if(a[i]>b[i-1][1]){
        b[i][0] = tmp;
        b[i][1]=a[i];
    }
    else{
        b[i][0] = tmp;
        b[i][1] = b[i-1][1];
    }
    if(b[i-1][0]>a[i]&&b[i-1][1]<a[i]){
        // cout<<a[i]<<" "<<b[i-1][0]<<":"<<b[i-1][0]<<" "<<b[i-1][1]<<endl;
        ans[b[i-1][0]]++;
        // ans[a[i]]--;
    }
    else if(b[i-1][0]<a[i]){
        ans[a[i]]--;
    }
}
// f(i,N){
//     cout<<b[i][0]<<" "<<b[i][1]<<endl;
// }
int mx=-2;
int ret=0;
ans[a[0]]--;
for(int i=1;i<=N;i++){
    // cout<<ans[i]<<endl;
    if(ans[i]>mx){
        mx=ans[i];
        ret=i;
    }
}
cout<<ret<<endl;
return 0;
}