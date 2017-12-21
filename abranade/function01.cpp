#include<iostream>
#include<bits/stdc++.h>
using namespace std;
istream read_hw(istream & in ,vector<double>& hw)
{
    if(in){
        //get rid of previous contents
        hw.clear();
        //read homework grades
        double x;
        while (in>>x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}
int main(){
    

    return 0;
}