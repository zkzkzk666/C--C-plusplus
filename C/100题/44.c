// 计算 1，2，3…100 的和。
#include<stdio.h>

int main()
{
    int sum=0;
    for (int i = 1; i <= 100; i++)
    {
        sum+=i;
    }
    printf("1，2，3…100 的和为：%d",sum);
    return 0;
}
