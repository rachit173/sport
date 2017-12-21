#include<bits/stdc++.h>
using namespace std;
int main(){
    int G,B;
    while(1){
        scanf("%d %d",&G,&B);
        if(G==-1||B==-1)
        break;
        if(G==0&&B==0){
            printf("0\n");
            continue;
        }
        if(G==B)
            printf("1\n");
        else if(G<B)
            printf("%d\n",(int)ceil(B*1.0/(G+1)));
        else
            printf("%d\n",(int)ceil(G*1.0/(B+1)));
    }

    return 0;
}