#include<iostream>
using namespace std;
#include<string>
//动物类，抽象类，抽象类无法实例化对象
class Animal
{
public:
    // //虚函数
    // virtual void speak(){
    //     cout<<"动物说话"<<endl;
    // }
    //纯虚函数，有这种函数后，此类变成抽象类
    virtual void speak()=0;

    Animal(){
        cout<<"动物构造函数调用"<<endl;
    }
    // //虚析构
    // virtual ~Animal(){
    //     cout<<"动物析构函数调用"<<endl;
    // }
    //纯虚析构
    virtual ~Animal()=0;
};
Animal::~Animal(){
    cout<<"动物析构函数调用"<<endl;
}

//猫类
class Cat:public Animal
{
public:
    //重写
    //子类必须重写父类中的纯虚函数，否则也属于抽象类
    void speak(){
        cout<<"猫说话"<<endl;
    }
};
//猫类plus
class CatPlus:public Animal
{
public:
    CatPlus(string name){
        cout<<"猫构造函数调用"<<endl;
        m_name=new string(name);
    }
    ~CatPlus(){
        if (m_name!=NULL)
        {
            cout<<"猫析构函数调用"<<endl;
            delete m_name;
            m_name=NULL;
        }
        
    }
    //重写
    //子类必须重写父类中的纯虚函数，否则也属于抽象类
    void speak(){
        cout<<*m_name<<"猫说话"<<endl;
    }
    string *m_name;
    
};

//狗类
class Dog:public Animal
{
public:
    //重写
    void speak(){
        cout<<"狗说话"<<endl;
    }
};

//动态多态，子类重写父类虚函数
void doSpeak(Animal &animal){
    animal.speak();
}


void test1(){
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
void test2(){
    Animal *animal=new CatPlus("666");
    animal->speak();
    delete animal;
}

int main(){
    // test1();
    test2();
    return 0;
}