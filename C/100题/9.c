// 用海伦公式求三角形面积。√𝑠(𝑠 − 𝑎)(𝑠 − 𝑏)(𝑠 − 𝑐)，其中 s 是周长的一半。
#include<stdio.h>
//包含头文件使用sqrt求算数平方根函数
#include<math.h>

double TriangleArea(double a,double b,double c){
    double s=(a+b+c)/2;
    // printf("%f\n",s);
    return sqrt(s*(s-a)*(s-b)*(s-c));
}


int main(){
    double a=3,b=4,c=5;
    printf("面积为%.12f",TriangleArea(a,b,c));
    return 0;
}