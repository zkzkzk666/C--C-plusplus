// 求 sinh(x)=(e^x - e^-x)/2，其中 e^x 用单独函数返回值
#include<stdio.h>
#include<math.h>

int main(){
    double x,sinh;
    printf("请输入一个数");
    scanf("%lf",&x);
    sinh=(exp(x)-exp(-x))/2;
    printf("sinh(%.2f)=%f",x,sinh);
    return 0;
}