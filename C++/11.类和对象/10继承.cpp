#include<iostream>
using namespace std;

//父类
class Base{
public:
    void header(){
        cout<<"头部"<<endl;
    }
    void footer(){
        cout<<"底部"<<endl;
    }
    void left(){
        cout<<"边栏"<<endl;
    }
    Base(){
        cout<<"Base构造"<<endl;
    }
    ~Base(){
        cout<<"Base析构"<<endl;

    }
};

//子类
class A:public Base{
public:
    void content(){
        cout<<"A内容"<<endl;
    }
    A(){
        cout<<"A构造"<<endl;
    }
    ~A(){
        cout<<"A析构"<<endl;

    }
};
//子类
class B:public Base{
public:
    void content(){
        cout<<"B内容"<<endl;
    }
};

void t1(){
    A a;
    B b;
    a.header();
    a.footer();
    a.left();
    a.content();
    cout<<"----------------"<<endl;
    b.header();
    b.footer();
    b.left();
    b.content();
}

void t2(){
    //先构造父类，在构造子类，再析构子类，最后析构父类  
    A a;
}
//父类
class Father{
public:
    int age;
};

//子类1
//继承之前加上关键字virtual变为虚继承
class S1:virtual public Father{
};
//子类2
class S2:virtual public Father{
};
//子类的子类
class Sun:public S1,public S2{
};

//菱形继承
void t3(){
    Sun sun;
    sun.S1::age=10;
    sun.S2::age=20;
    cout<<sun.age<<endl;
}
int main(){
    // t1();
    // t2();
    t3();
    return 0;
}