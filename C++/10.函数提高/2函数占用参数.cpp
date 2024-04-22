#include<iostream>
using namespace std;

void fun(int a,int){
    cout<<"666";
}
//占位参数可以有默认参数
void fun1(int a,int=10){
    cout<<"666";
}

int main(){
    fun(10,1);//占位参数必须填补
    fun1(10);//有默认参数时可以不用填写
    return 0;
}