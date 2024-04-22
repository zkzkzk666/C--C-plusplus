// 用随机函数产生 10 个互不相同的两位整数存放到一维数组中，并输出其中的素数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

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
    //获取当前时间
    time_t t;
    //创建一维数组
    int arr[N];
    /* 初始化随机数发生器 */
    srand((unsigned) time(&t));
    printf("该数组为：\n");
    for (int i = 0; i < N; i++)
    {
        //随机数取值范围为1~100
        printf("%d ",arr[i]=rand()%100+1);
    }
    printf("\n其中的素数为：\n");
    for (int i = 0; i < N; i++)
    {
        if (isPrimeNumber(arr[i]))
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}