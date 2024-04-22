// 一个偶数总能表示为两个素数之和。输入一个偶数并将其分解为两个素数

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
    int n;
    printf("请输入一个大于二的偶数：");
    scanf("%d",&n);
    for (int i = 1; i < n; i++)
    {
        //i是素数并且n-i也是素数时就满足题意
        if (isPrimeNumber(i)&&isPrimeNumber(n-i))
        {
            printf("%d=%d+%d",n,i,n-i);
            //输出结果后跳出循环，不然有两个或多个结果
            break;
        }
    }
    return 0;
}