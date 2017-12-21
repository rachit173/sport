//rachit_
#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,i,t;
        cin>>n>>m;
        vector<int> a(m);
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        sort(a.begin(),a.end());
        int value,hero,ma,tp;
        value=a[0];
        tp=1;
        hero=-1;
        ma=-1;
        for(int i=1;i<m;i++){
            if(a[i]==a[i-1])
            tp++;
            else{
                if(tp>=ma){
                    hero=value;
                    ma=tp;
                }
                tp=1;
                value=a[i];
            }
        }
                        if(tp>=ma){
                    hero=value;
                    ma=tp;
                }

        cout<<hero<<endl;
    }
    return 0;
}