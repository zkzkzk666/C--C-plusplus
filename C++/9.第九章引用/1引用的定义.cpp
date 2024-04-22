#include<iostream>
using namespace std;

void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a=10;
    //引用的本质就是一个指针常量
    //引用b为a的别名
    int& b=a;//自动转换为int *const ref=&a
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    b=100;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    int x=10;
    int y=20;
    swap(x,y);
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    return 0;
}