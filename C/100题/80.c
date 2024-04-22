// 判断 101-200 之间有多少个素数，并输出所有素数
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
    //素数的个数
    int sum=0;
    printf("101-200的素数有：\n");
    for (int i = 101; i <=200; i++)
    {
        if (isPrimeNumber(i))
        {
            printf("%d ",i);
            sum++;
        }
    }
    printf("\n101-200的素数有%d个",sum);
    return 0;
}