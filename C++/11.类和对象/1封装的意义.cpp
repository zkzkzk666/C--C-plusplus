#include<iostream>
using namespace std;

//把PI定义为3.1415
#define PI 3.1415

//创建一个圆类
class Circle
{
//访问权限，公共权限
public:
    //属性
    int c_r;//半径
    //计算圆的周长
    double c(){
        return 2*PI*c_r;
    }
    //给半径赋值
    void set_r(int r){
        c_r=r;
    }
};

int main(){
    //创建一个圆对象，实例化
    Circle c1;
    //把圆的半径赋值为2
    c1.c_r=2;
    cout<<c1.c()<<endl;
    
    Circle c2;
    //把圆的半径赋值为10
    c2.set_r(10);
    cout<<c2.c()<<endl;
    return 0;
}