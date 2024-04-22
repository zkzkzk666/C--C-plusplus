//输入一个整数，输出该整数的所有素数因子。例如，输入 120, 输出 2、3 、5
#include<stdio.h>

//判断一个数n是否为素数
int isPrimeNumber(int n){
    //1不是素数
    if (n==1)
    {
        return 0;
    }
    for (int i = 2; i <=(n/2); i++)
    {
        //当有n能被整除时，不是素数
        if ((n%i)==0)
        {
            return 0;
        }
    }
    return 1;
} 
int main(){
    int num;
    printf("请输入一个整数\n");
    scanf("%d",&num);
    for (int i = 1; i < num; i++)
    {
        //当取模不为0时i为num的因子
        if ((num%i)==0)
        {
            if (isPrimeNumber(i))
            {
                printf("%d\n",i);
            }
        } 
    }
    return 0;
}