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

    Person(int age,int height)
    {   //有参
        m_age=age;
        m_height=new int(height);
        cout<<"有参构造函数调用"<<endl;
    }

    Person(const Person& p)
    {   //拷贝构造函数
        m_age=p.m_age;
        // m_height=p.m_height;//编辑器默认实现这行代码，只是浅拷贝
        m_height=new int(*p.m_height);
        cout<<"拷贝构造函数调用"<<endl;
    }
//析构函数，不能有参数
    ~Person()
    {
        if (m_height!=NULL)
        {
            delete m_height;
            m_height=NULL;
        }
        cout<<"析构函数调用"<<endl;
    }
    int m_age;
    int *m_height;
};

int main(){
    Person p1(10,160);
    Person p2(p1);
    cout<<"p1年龄："<<p1.m_age<<"p1身高："<<*p1.m_height<<endl;
    cout<<"p2年龄："<<p2.m_age<<"p2身高："<<*p2.m_height<<endl;
}