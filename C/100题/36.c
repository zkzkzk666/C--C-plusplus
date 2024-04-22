//用弦截法求 func(x)=x^3-5*x^2+16*x-80=0 的根
//弦截法就是用函数上两点，连线的斜率近似代替f`(x)
//公式为Xn+1=Xn−(Xn−Xn−1)*func(Xn)/(func(Xn)−f(Xn−1))

#include<stdio.h>
#include<math.h>

//求f(x)的值
double func(double x){
    return x*x*x-5*x*x+16*x-80;
}

int main(){
    double x1,x2,temp;
    do
    {
        printf("输入两个数x1,x2:");
        scanf("%lf%lf",&x1,&x2);
    }
    // 当输入两个数大于0为真时，继续重新输入,直到f(x1)和f(x2)一正一负
    //一正一负代表在x1和x2中间有f(x)=0的根
    while (func(x1)*func(x2)>= 0);
    do
    {
        temp=x2-(x2-x1)*func(x2)/(func(x2)-func(x1));
        if (func(temp)*func(x1)>0)
        {
            x1=temp;
        }
        else{
            x2=temp;
        }
    }
    while (func(x2)>1e-7);
    printf("%.12f",x2);
    return 0;
}