#include<iostream>
#include<string>
using namespace std;

//class默认权为私有
//struct默认为公共

class Person
{
//私有权限，成员类内可以访问，类外不可以访问，儿子不能访问父亲的私有内容
private:
    int m_password;
    

//公共属性,成员类内可以访问，类外可以访问
public:
    string m_name;
    //成员类内都可以访问
    void func(){
        m_name="666";
        m_car="111";
        m_password=1234;
    }

//保护权限，成员类内可以访问，类外不可以访问，儿子可以访问父亲的保护内容
protected:
    string m_car;
};

int main(){
    Person p1;
    p1.m_name="121";
    // p1.m_car="222";不可以访问
    // p1.m_password=123;不可以访问
    cout<<p1.m_name<<endl;
    return 0;
}