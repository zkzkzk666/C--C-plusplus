//用牛顿迭代法求方程 2x^3-4x^2+3x-6=0 在 1.5 附近的根
//公式为X（n+1)=Xn-f(Xn)/f`(Xn)

#include<stdio.h>
#include<math.h>

int main(){
    //初始状态下两根的值
    double x1=1.5,x2=0;
    //当根的精度到达要求时，就停止迭代
    //fabs()求浮点数的函数值，精度比abs更高，abs()主要求整数的绝对值
    while (fabs(x2-x1)>=1e-6)
    {
        x1=x1-(2*x1*x1*x1-4*x1*x1+3*x1-6)/(6*x1*x1-8*x1+3);
        x2=x1-(2*x1*x1*x1-4*x1*x1+3*x1-6)/(6*x1*x1-8*x1+3);
    }
    printf("%.12f",x2);
    
    return 0;
}