/*有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月
又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？ 
程序分析： 兔子的规律为数列1,1,2,3,5,8,13,21（斐波那契数列）.... */
#include<stdio.h>

//递归函数，求斐波那契数列
int func(int n){
    if (n<=2)
    {
        return 1;
    }
    return func(n-1)+func(n-2);
}

int main(){
    int n;
    printf("请输入月份：");
    scanf("%d",&n);
    printf("第%d个月，兔子的总数为：%d",n,func(n));
    return 0;
}