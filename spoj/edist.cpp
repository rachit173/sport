//there is a great difference between library function strlen and size of the STL 
//strlen is O(n) while .size() is O(1)
#include<bits/stdc++.h>
using namespace std;
char a[2001],b[2001];
int sza,szb;
int memo[2005][2005];
int dp(int sta,int stb){

    if(memo[sta][stb]!=-1)
    return memo[sta][stb];
    if(stb==szb){
    memo[sta][stb]=strlen(a)-sta;
    return memo[sta][stb];    
    }
    if(sta==sza){
        memo[sta][stb]=strlen(b)-stb;
        return memo[sta][stb];
    }
    if(a[sta]==b[stb]){
        memo[sta][stb]= dp(sta+1,stb+1); //no replacing and deleting 
    }
    else{
        memo[sta][stb]=min(1+dp(sta+1,stb+1),min(1+dp(sta+1,stb+0),1+dp(sta+0,stb+1)));    //replacing ,deleting,inserting before
    }
    return memo[sta][stb];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(memo,-1,sizeof(memo));
        scanf("%s %s",&a,&b);
        sza=strlen(a);
        szb=strlen(b);
        cout<<dp(0,0)<<endl;
    }
    return 0;
}