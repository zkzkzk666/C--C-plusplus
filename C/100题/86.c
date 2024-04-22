// 求100之内的素数
#include<stdio.h>

#define N 100

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
    printf("100以内的素数有：");
    for (int i = 1; i < N; i++)
    {
        if (isPrimeNumber(i))
        {
            printf("%d ",i);
        }
    }
    return 0;
}