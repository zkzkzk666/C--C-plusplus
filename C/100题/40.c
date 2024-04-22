// 用递归法求 n 阶勒让德多项式的值
// 递归公式为：
// n==0,P(n)(x)=1
// n==1,P(n)(x)=x
// n>1,P(n)(x)=((2*n-1)*x - P(n-1)(x) - (n-1)*P(n-2)(x)) / n
#include<stdio.h>

double func(int n,int x){
    if (n==0)
    {
        return 1;
    }
    
    if (n==1)
    {
        return x;
    }
    if (n>1)
    {
        return ((2*n-1)*x - func(n-1,x) - (n-1)*func(n-2,x)) /(n);
    }
}
int main()
{
    //n为阶数，x为参数
    int n,x;
    printf("请输入n\n");
    scanf("%d",&n);
    printf("请输入x\n");
    scanf("%d",&x);
    printf("P%d(%d)=%f",n,x,func(n,x));
    return 0;
}
