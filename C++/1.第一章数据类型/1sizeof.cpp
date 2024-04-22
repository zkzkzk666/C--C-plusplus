#include<iostream>
using namespace std;

int main(){
    //整型：short（2）int（4）long（4）long long（8）
    cout<<"short所占内存空间为"<<sizeof(short)<<endl;
    cout<<"int所占内存空间为"<<sizeof(int)<<endl;
    cout<<"long所占内存空间为"<<sizeof(long)<<endl;
    cout<<"long long所占内存空间为"<<sizeof(long long)<<endl;
    cout<<sizeof(int *);
    return 0;
}