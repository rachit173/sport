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
#define first ff
#define second ss
#define f(i,n) for(int i=0;i<n;i++)
#define f2(i,j,n,m) f(i,n) f(j,m)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define RESET(a,val) memset(a,val,sizeof(a))
char str[5000000];
int main(){
    int  n;
    while(sc(n)==1){
        char s[n+3];
        scanf("%s",s);
        int sz=strlen(s);
        int lps[sz];
        //preprocessing
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<sz){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        //f(j,sz) {pf(lps[j]);sp;}
        ///////////////
        int ans=0;
        i=0;
        int j=0;
        char c;
        //char str[5000000];
        scanf("%s",str);
        int N=strlen(str);
        while(i<N){
            if(s[j]==str[i]) {j++;i++;}
            if(j==sz){ pf(i-j);br;ans++;j=lps[j-1];}
            else if(i<N && s[j]!=str[i]){
                if(j!=0) j=lps[j-1];
                else i++;
            }   
        }
         br;
    }
    return 0;
}