#include<iostream>
using namespace std;

//函数默认参数
int add(int a,int b=10){
    return a+b;

}
//声明和实现只能有一个有默认参数
int add1(int a=10,int b=10);
// int add1(int a=10,int b=10){
//     return a+b;
// }错误
int add1(int a,int b){
    return a+b;
}
int main(){
    int a=10;
    int result=add(10);
    cout<<result<<endl;
    int result1=add(10,20);
    cout<<result1<<endl;
    int result2=add1();
    cout<<result2<<endl;
    return 0;
}