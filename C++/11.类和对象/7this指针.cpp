#include<iostream>
using namespace std;


class Person{
public:
    int age;
    Person(int age){
        this->age=age;
    }
    Person& addAge(Person &p){
        this->age+=p.age;
        //*this指向对象本体
        return *this;
    }
};


int main(){
    // Person p;
    // cout<<sizeof(p);//如果对象为空（没有属性），则sizeof(p)为1
    Person p1(10);
    cout<<p1.age<<endl;
    Person p2(p1);
    p2.addAge(p1).addAge(p1);
    cout<<p2.age<<endl;

    return 0;
}