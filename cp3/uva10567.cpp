#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<char,int> ai;
typedef vector<ii> vii;
void check(const char *q,vector<ai> &arr){
            int min_index=-1,start;
        vector <ai>::iterator up;
        //cout<<q.size()<<" "<<arr.size()<<endl;

        for(int i=0;i<strlen(q);i++)
        {
                up=upper_bound(arr.begin(),arr.end(),make_pair(q[i],min_index));
                min_index=(*up).second;
               // cout<<min_index<<(*up).first<<endl;
                if(i==0)
                    start=min_index;
                if(min_index>=arr.size()||(*up).first!=q[i])
                {
                    cout<<"Not matched\n";
                    return;
                }
        }
        printf("Matched %d %d\n",start,min_index);
}
int main(){
    string s;
    cin>>s;
    vector<ai> arr(s.size());
    for(int i=0;i<s.size();i++)
        arr[i]=make_pair(s[i],i);
    sort(arr.begin(),arr.end());
    int Q;
    cin>>Q;
    string q;
    while(Q--){
        q.resize(0);
        cin>>q;
        //cout<<q;
        check(q.c_str(),arr);
    }
    return 0;
}