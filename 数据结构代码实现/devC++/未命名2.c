/*写一个函数验证哥德巴赫猜想：一个不小于 6 的偶数可以表示为两个素数之和，如
6=3+3，8=3+5，10=3+7…在主函数中输入一个不小于 6 的偶数 n，然后调用函数 gotbaha，
在 gotbaha 函数中再调用 prime 函数，prime 函数的作用是判别一个数是否为素
数。在 godbaha 函数中输出以下形式的结果：34=3+31。*/
#include<stdio.h>
int gotbaha(int n){
    //双重循环找到两个素数
    for (int num1 = 0; num1 <n; num1++)
    {
        for (int num2 = 0; num2 < n; num2++)
        {
            //当num1和num2都为素数并且两数之和等于n时即可输出
            if (prime(num1)&&prime(num2)&&num1+num2==n)
            {
                printf("%d=%d+%d",n,num1,num2);
                //用return直接跳出循环
                return 1;
            }
        }
    }
}
//判断一个数是否为素数
int prime(int num){
    //1不是素数
    if (num==1)
    {
        return 0;
    }
    for (int i = 2; i <=(num/2); i++)
    {
        //当有n能被整除时，不是素数
        if ((num%i)==0)
        {
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("请输入一个不小于 6 的偶数");
    scanf("%d",&n);
    gotbaha(n);
    return 0;
}
