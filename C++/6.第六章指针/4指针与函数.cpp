#include<iostream>
using namespace std;

void swap(int *p1,int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main(){
    //地址传递
    int a=10;
    int b=20;
    swap(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}