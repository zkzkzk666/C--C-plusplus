/*定义一个 Box(盒子)类，在该类定义中包括数据成员和成员函数。 数据成员：length
（长）、width（宽）和 height（高）； 成员函数：构造函数 Box，设置盒子长、宽和
高 3 个初始数据；成员函数 setBox 对成员赋值；成员函数 volume 计算盒子的
体积。 在 main 函数中，要求创建 Box 对象，输入长，宽，高，求盒子的体积。*/
#include<iostream>
using namespace std;

class Box
{
private:
    int length;//长
    int width;//宽
    int height;//高
public:
    Box(){
        //初始值都为10
        this->height=10;
        this->length=10;
        this->width=10;
    }
    //设置长宽高
    void setBox(int length,int width,int height){
        this->height=height;
        this->length=length;
        this->width=width;
    }
    //求体积
    int volume(){
        return this->height*this->length*this->width;
    }
};



int main(){
    //创建Box对象
    Box b;
    int x,y,z;
    printf("请输入盒子的长：");
    scanf("%d",&x);
    printf("请输入盒子的宽：");
    scanf("%d",&y);
    printf("请输入盒子的高：");
    scanf("%d",&z);
    b.setBox(x,y,z);
    printf("盒子的体积为：%d",b.volume());
    return 0;
}