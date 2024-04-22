// 求 N 的阶乘的和。例如：1！+2！+3！+…n！
#include<stdio.h>
//求阶乘
int factorial(int n){
    //递归求阶乘
    if (n==1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

//求阶乘的和
int func(int n){
    int sum=0;
    for (int i = 1; i <=n; i++)
    {
        sum+=factorial(i);
    }
    return sum;
}

int main(){
    int n;
    printf("请输入n\n");
    scanf("%d",&n);
    printf("结果为：%d\n",func(n));
    return 0;
}