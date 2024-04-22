#include<iostream>
using namespace std;

int *fun(){
    int a=10;
    return &a;//不能返回局部变量的地址
}
int main(){
    int *p=fun();
    cout<<*p<<endl;
    cout<<*p<<endl;

    return 0;
}