#include<iostream>
using namespace std;



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
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test1(){
    Person p1(10);
    Person p2(p1);
    cout<<p2.age<<endl;
}

//2.值传递的方式给函数参数传值
void do_work1(Person p){
    
}
void test2(){
    Person p;
    do_work1(p);
}
//3.值方式返回局部对象,编译器优化，运行后为相同对象并未调用拷贝构造函数
Person do_work2(){
    Person p1;
    cout<<(int*)&p1<<endl;
    return p1;
}
void test3(){
    Person p=do_work2();
    cout<<(int*)&p<<endl;

}
int main(){
    // test1();
    // test2();
    test3();

}