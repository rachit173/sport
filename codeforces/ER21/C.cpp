#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
bool cmp(ii a,ii b)
{
    return a.second<b.second;
}
int main(){
    int n,w;
    cin>>n>>w;
    vi a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int minima=0,maxima=0;
    for(int i=0;i<n;i++){
    minima+=ceil(a[i]/2.0);
    maxima+=a[i];
    }
    if(w<minima||w>maxima)
        cout<<"-1\n";
    else{
        vii lst(n);
        for(int i=0;i<n;i++){
            lst[i]=make_pair(a[i],i);
        }
        sort(lst.rbegin(),lst.rend());
        int tealeft=w-minima;
        //cout<<tealeft<<endl;
        int i=0;
        while(tealeft>=0&&i<n){
            lst[i].first=min(tealeft,(int)floor(lst[i].first*1.0/2))+ceil((int)lst[i].first*1.0/2);
            tealeft-=min(tealeft,(int)floor(lst[i].first*1.0/2));
            i++;
        }
        sort(lst.begin(),lst.end(),cmp);
        for(int i=0;i<n;i++)
        cout<<lst[i].first<<" ";
        cout<<endl;
    }
    return 0;
}