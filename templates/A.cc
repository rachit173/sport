#include<iostream>
using namespace std;
enum Type {str,num};
constexpr double square(double x) {return x*x;}
union Value {
    char *c;
    int i;
}
struct Person {
    char *name;
    Type t;
    Value roll_no;
}
int main(){
    Person p;
    
    return 0;
}