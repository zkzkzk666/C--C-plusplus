#include<iostream>
using namespace std;

int main(){
    int a=10;
    int b=20;
    //const修饰指针-常量指针
    const int *p=&a;
    //*p=20;//指针指向的值不能改变
    p=&b;//指针指向可以改变

    //const修饰常量-指针常量
    int *const p2=&a;
    *p2=20;//指针指向的值可以改变
    // p2=&b;指针指向不能改变

    //const既修饰常量又修饰指针
    const int *const p3=&a;
    // *p3=20;//指针指向的值不能改变
    // p3=&b;指针指向不能改变
    return 0;
}