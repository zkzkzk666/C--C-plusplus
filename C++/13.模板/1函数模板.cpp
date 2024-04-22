#include<iostream>
using namespace std;


//模板必须确认数据类型才可以调用
template<typename T>

void my_swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

void test1(){
    int a=10;
    int b=20;
    //自动类型推导,推导出的T类型必须一致
    // my_swap(a,b);
    //显示指定类型
    my_swap<int>(a,b);
    cout<<a<<" "<<b<<endl;
}

int main(){
    test1();

    return 0;
}