//rachit_
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define ll long long int
int main(){
    int T;
    cin>>T;
    long double a,b,k,t;
    while(T--){
        cin>>a>>b>>k;
        if(abs(b)>abs(a)){
            t=a;
            a=b;
            b=t;
        }
        if((abs(a*a-b*b)/2*k)+k/2<a){
            cout<<"-1"<<endl;
            continue;
        }
        long double t1=sqrt((a*a-b*b)/(2*k)+(k/2)-a);
        long double t2=sqrt((a*a-b*b)/(2*k)+(k/2)+a);
        long double y=t1*t2;
        if(y==0){
                        cout<<"1"<<"\n"<<"0 0"<<"\n";
            continue;
        }
        printf("2\n");
        printf("0 %.12LG\n",y);
        printf("0 %.12LG\n",-1.0*y);
    }
    return 0;
}