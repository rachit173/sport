#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sc1(a) scanf("%lld",&a);
#define pf1(a) printf("%lld",a);
#define sc2(a) scanf("%d %d",&a.first,&a.second);
#define br printf("\n");
#define sp printf(" ");
#define ll long long int
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  char c[200];
  while(scanf("%s",c)==1){
    int n=strlen(c);
    int num1=0,num2=0;
    for(int i=0;i<n;i++) if(c[i]=='_') num1++;
    for(int i=0;i<n;i++) if(c[i]>='A'&&c[i]<='Z') num2++;
    int opt=0;
    for(int i=1;i<n;i++){
      if(c[i]=='_'&&c[i-1]==c[i]) {opt=1;break;}
    }
    if(opt==1) {printf("Error!\n");continue;}
    if(num1>0&&num2>0) printf("Error!\n");
    else if((c[0]>='A'&&c[0]<='Z')||c[0]=='_'||c[n-1]=='_') printf("Error!\n");
    else if(num1>0){
        int i=0;
        while(i<n){
        if(c[i]=='_'){
          i++;
          if(i<n) printf("%c",c[i]+'A'-'a');
        }
        else printf("%c",c[i]);
      i++;
    }
    br;
    }
    else{
      for(int i=0;i<n;i++){
        if(c[i]>='A'&&c[i]<='Z') printf("_%c",c[i]+'a'-'A');
        else printf("%c",c[i]);
      }
      br;
    }
  }
return 0;
}
