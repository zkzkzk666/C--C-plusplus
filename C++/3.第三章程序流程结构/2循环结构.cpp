#include<iostream>
using namespace std;

int main(){
    //输出0~10 while
    int a=0;
    while (a<=10)
    {
        cout<<a<<endl;
        a++;
    }
    //输出0~10 do while
     int b=0;
    do
    {
        cout<<b<<endl;
        b++;
    } while (b<=10);
    //输出0~10 do while
    for (int i = 0; i <=10; i++)
    {
        cout<<i<<endl;
    }
    
    return 0;
}