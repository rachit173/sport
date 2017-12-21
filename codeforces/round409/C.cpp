#include<bits/stdc++.h>
#define ll long long int
  using namespace std;
  struct data{
    ll a;
    ll b;
    //double time=(b*1.0/a);
  };
  bool cmp(data &i,data &j)
  {
    return i.b*j.a>j.b*i.a;
  }
  int main(){
  int n,p;
  cin>>n>>p;
  vector <data> vec(n);
  for(int i=0;i<n;i++)
    scanf("%lld %lld",&vec[i].a,&vec[i].b);
  bool inf=false;
  sort(vec.begin(),vec.end(),cmp);
 // for(int i=0;i<n;i++)
   // cout<<vec[i].a<<" "<<vec[i].b<<endl;
  int j=0;
  ll suma=0;
  ll sumb=0;
  for(int i=0;i<n;i++){ 
    suma+=vec[i].a;
    sumb+=vec[i].b;
}
  if(suma<=p)
    inf=true;
    ll t1,t2;
  while(!inf&&j<n){
    t1=sumb;
    t2=suma-p;
    if(vec[j].b*t2>vec[j].a*t1){
      sumb-=vec[j].b;
      suma-=vec[j].a;
      j++;
    }
    else break;
    if(suma<=p)break;
  }
  if(inf==true)
    cout<<"-1"<<endl;
    else{
  double ans=(sumb*1.0)/(suma-p);
  printf("%lf\n",ans);
    }
  return 0;
  }
