#include<iostream>
using namespace std;


//对象初始化和清理
// 1.构造函数进行初始化操作
class Person
{
public:
//构造函数,有参构造，无参构造
    Person()
    {   //无参
        cout<<"无参构造函数调用"<<endl;
    }

    Person(int a)
    {   //有参
        age=a;
        cout<<"有参构造函数调用"<<endl;
    }

    Person(const Person& p)
    {   //拷贝构造函数
        age=p.age;
        cout<<"拷贝构造函数调用"<<endl;
    }
//析构函数，不能有参数
    ~Person()
    {
        cout<<"析构函数调用"<<endl;
    }
    int age;
};

void test(){
    //调用方法
    //1.括号法
    Person p;//默认构造函数调用
    Person p1(10);//有参构造函数调用
    Person p2(p1);//拷贝构造函数调用

    //2.显示法
    Person a1;//默认构造函数调用
    Person a2=Person(10);//有参构造函数调用
    Person a3=Person(a2);//拷贝构造函数调用

    //3.隐式转换法
    Person a4=10;//Person a4=Person(10);
    Person a5=a4;//Person a5=Person(a4);
}

int main(){
    test();
    return 0;
}