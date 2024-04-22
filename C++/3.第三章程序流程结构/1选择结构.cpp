#include<iostream>
using namespace std;

int main(){
    int a=10,b=6;
    //三目运算符
    int c=a>b?a:b;
    cout<<c<<endl;
    //if循环语句
    if (a>b)
    {
        cout<<"a>b"<<endl;
    }
    else
    {
        cout<<"b>=a"<<endl;
    }
    //switch语句
    int x=0;
    cin>>x;
    switch (x)
    {
    case 1:
        cout<<"1";
        break;
    case 2:
        cout<<"2";
        break;
    case 3:
        cout<<"3";
        break;
    case 4:
        cout<<"4";
        break;
    case 5:
        cout<<"5";
        break;
    default:
        cout<<"666";
        break;
    }
    return 0;
}