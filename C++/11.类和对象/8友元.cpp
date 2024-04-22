#include<iostream>
using namespace std;

class Std;
class TT{
public:
    void visit3(Std *s);
    void visit4(Std *s);
};
class Std
{
    //让全局函数visit1函数成为友元
    friend void visit1(Std *s);
    //让类T成为友元
    friend class T;
    //让类TT的成员函数visit3成为友元
    friend void TT::visit3(Std *s);
private:
    int a;//私有属性
public:
    int b;//公共属性
    Std(){
        a=10;
        b=20;
    }
};
void TT::visit3(Std *s){
        cout<<"正在访问:"<<s->b<<endl;
        //私有属性在类外不能访问，成为友元后可以访问
        cout<<"正在访问:"<<s->a<<endl;
    }
void TT::visit4(Std *s){
        cout<<"正在访问:"<<s->b<<endl;

        //私有属性在类外不能访问，成为友元后可以访问
        // cout<<"正在访问:"<<s->a<<endl;
    }

class T{
public:
    void visit2(Std *s){

    cout<<"正在访问:"<<s->b<<endl;

    //私有属性在类外不能访问，成为友元后可以访问
    cout<<"正在访问:"<<s->a<<endl;
}
};



//全局函数做友元
void visit1(Std *s){
    cout<<"正在访问:"<<s->b<<endl;
    //私有属性在类外不能访问，成为友元后可以访问
    cout<<"正在访问:"<<s->a<<endl;

}

void test1(){
    Std s;
    visit1(&s);  
}

void test2(){
    Std s;
    T t;
    t.visit2(&s);  
}
void test3(){
    Std s;
    TT tt;
    tt.visit3(&s);  
}
int main(){
    // test1();
    // test2();
    test3();
    return 0;
}