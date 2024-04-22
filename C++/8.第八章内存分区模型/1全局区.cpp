#include<iostream>
using namespace std;

//全局变量
int g_a=10;
int g_b=10;

//全局常量
const int c_g_a=10;
const int c_g_b=10;

int main(){
    //普通局部变量
    int a=10;
    int b=10;
    //静态变量
    static int s_a=10;
    static int s_b=10;
    
    //局部常量
    const int c_l_a=10;
    const int c_l_b=10;

    cout<<"a:"<<&a<<endl;
    cout<<"b:"<<&b<<endl;
    cout<<"g_a:"<<&g_a<<endl;
    cout<<"g_b:"<<&g_b<<endl;
    cout<<"s_a:"<<&s_a<<endl;
    cout<<"s_b:"<<&s_b<<endl;
    cout<<"c_g_a:"<<&c_g_a<<endl;
    cout<<"c_g_b:"<<&c_g_b<<endl;
    cout<<"c_l_a:"<<&c_l_a<<endl;
    cout<<"c_l_b:"<<&c_l_b<<endl;

    //字符串常量
    cout<<"字符串常量地址:"<<&"hello"<<endl;

    return 0;
}