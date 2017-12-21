#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    double x;
    double sum=0;
    int count=0;
    while(cin>>x){
        sum+=x;
        count++;
    }
    //write the result
    streamsize prec=cout.precision();
    cout<<"Your average marks are "<<setprecision(4)<<sum/count
        <<setprecision(prec)<<endl;
    //printf("%.2f\n",sum/count);

    return 0;
}