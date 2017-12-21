#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int,int> ii;
typedef pair<int,string> si;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
  string s;
  cin>>s;
  bool opt=false;
  int count=0;
  for(int i=1;i<s.size();i++)
    if(s[i]=='K'&&s[i-1]=='V')
    count++;
  size_t found = s.find("VVV");
  if(found!=string::npos)
    opt=opt|true;
  found=s.find("KKK");
  if(found!=string::npos)
    opt=opt|true;
  if(s.size()>1){
  if(s[0]=='K'&&s[1]=='K')
    opt=opt|true;
  if(s[s.size()-1]=='V'&&s[s.size()-2]=='V')
    opt=opt|true;
  }
  printf("%d\n",count+opt);
  return 0;
}
