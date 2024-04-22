#include<iostream>
using namespace std;

class Person{
public:
    //1.所有对象共享同一份数据
    //2.编译阶段就分配内存
    //3.类内声明，类外初始化操作
    //静态成员变量
    static int a;
    int b;
    //静态成员函数,可以访问静态成员变量，不能访问静态非静态成员变量
    static void func(){
        a=100;
        // b=10;不能访问
        cout<<"666"<<endl;
    }
    
};
//类外初始化操作
int Person::a=100;

int main(){
    Person p;
    //通过类名访问静态成员变量,静态成员函数
    cout<<p.a<<endl;
    p.func();
    //通过作用域访问静态成员变量,静态成员函数
    cout<<Person::a<<endl;
    Person::func();
    Person p1;
    p1.a=200;
    cout<<p.a<<endl;
    cout<<p1.a<<endl;
    return 0;
}