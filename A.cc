#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 0;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char c[105];
    scanf("%s",c);
    int n;
    int arr[105]={0};
    arr[0]=arr[1]=1;
    for(int i=2;i<100;i++){
        if(arr[i]==1) continue;
        for(int j=2*i;j<100;j+=i) arr[j] = 1;
    }
    //for(int i=0;i<100;i++) printf("%d ",arr[i]);
    int a[10]={0};
    int sz = strlen(c);
    for(int i=0;i<sz;i++){
        if(arr[i+1]==0){
           // printf("%d",c[i]-'0');
            a[(c[i]-'0')] = 1;
        }
    }
    //for(int i=0;i<10;i++) printf("%d ",a[i]);
    //printf("\n");
    int l = 1;
    for(int i=1;i<10;i++){
        if(a[i]){
            int g = gcd(i,l);
            l = (l*(i))/g;
        }
    }
    int b[10]={0};
   // printf("%d\n",l);
    while(l>0){
        b[l%10]++;
        l = l/10;
    }
    //for(int i=0;i<10;i++) printf("%d ",b[i]);
    char s1[100];
    int top = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<b[i];j++) s1[top++] = i+'0';
    }
    s1[top]='\0';
    char s2[100];
    int top1=0;
    int sz1 = strlen(s1);
    int z;
    if(sz1>=1){
        z = s1[1]-'0';
    for(int j=3;j<sz1;j+=2){
    //    printf("%c",s1[j]);
        if(z==0||(s1[j]-'0')==0) z=z>(s1[j]-'0')?z:(s1[j]-'0'); 
        else z = gcd(z,s1[j]-'0');
    }
    }
    int d[10]={0};
    //printf("%d\n",z);
    if(z>0){
    while(z>0){
        d[z%10]++;
        z = z/10;
    }
    }
    else d[0]++;
    for(int i=9;i>=0;i--){
        for(int j=0;j<d[i];j++) s2[top1++] = i+'0';
    }
    s2[top1] = '\0';
    printf("%s%s",s1,s2);
    return 0;
}
