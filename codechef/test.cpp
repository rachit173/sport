#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>
// #include<cstdio>
#include<stdio.h>
using namespace std;
#define pf(a) printf("%d",a)
#define pf1(a) printf("%lld",a)
#define br printf("\n")
#define sp printf(" ")
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,st,n) for(int i=st;i<n;i++)
int main(){
int T=3;
srand(time(NULL));
while(T--){
    int N=rand()%100007;
    int M=rand()%100005;
    pf(N);sp;pf(M);br;
    cout<<"1 ";
    int a,b;
    a=rand()%N+1;
    b=rand()%N+1;
    if(a>b){
        cout<<b<<" "<<a<<"\n";
    }
    else{
        cout<<a<<" "<<b<<"\n";
    }
    f1(i,2,M+1){
        
        int c=rand()%2;
        cout<<c+1<<" ";
        if(c+1==1){
            a=rand()%N+1;
            b=rand()%N+1;
        if(a>b){
            cout<<b<<" "<<a<<"\n";
        }
        else{
            cout<<a<<" "<<b<<"\n";
        }
        }else{
            a=rand()%(i-1)+1;
            b=rand()%(i-1)+1;
            if(a>b){
                cout<<b<<" "<<a<<"\n";
            }
            else{
                cout<<a<<" "<<b<<"\n";
            }
        }   
    }   
}
return 0;
}
