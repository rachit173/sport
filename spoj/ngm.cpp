#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
    int N;
    cin>>N;
    if(N%10==0)
        cout<<"2"<<endl;
    else
    {
        cout<<"1\n"<<N%10<<"\n";
    }

    return 0;
}