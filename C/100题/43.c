// 用递归方法求 𝑓(𝑥) = ∑ (𝑖^2)
#include<stdio.h>

int func(int n){
    if (n==1)
    {
        return 1;
    }
    else{
        return n*n+func(n-1);
    }
}

int main()
{
    int n;
    printf("请输入一个整数");
    scanf("%d",&n);
    printf("%d",func(n));
    return 0;
}
