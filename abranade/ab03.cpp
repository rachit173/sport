//this program depicts the use of cpp I/O method of taking input a string along whitespaces 
//other than the new line character
//The numerical specifies that n-1 characters will be stored in the array
#include<cstring>
#include<iostream>
using namespace std;
int main(){
  char s[20];
  cin.getline(s,20);
  cout<<s;
  return 0;

}
