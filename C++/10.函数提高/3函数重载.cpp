#include<iostream>
using namespace std;

//函数重载
void fun(){
    cout<<"1"<<endl;
}
void fun(int a){
    cout<<"2"<<endl;
}void fun(char a){
    cout<<"3"<<endl;
}void fun(double a){
    cout<<"4"<<endl;
}

int main(){
    fun();
    fun(1);
    fun('a');
    fun(1.0);
    return 0;
}