#include<iostream>
using namespace std;

int main(){
    //*代表解引用
    int a=10;
    int *p=&a;
    //32位操作系统占4，64位系统占8
    cout<<sizeof(p)<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p;
    return 0;
}
