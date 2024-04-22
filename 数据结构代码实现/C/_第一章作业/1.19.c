//计算i!*2^i(i=0,1,2,...,n-1)的值并存入数组a[arrsize]中。
//假设整数最大值为MAXINT，则当n>arrsize或对某个k(0=<k<=n-1)使k!*2^k>MAXINT时，应该按出错管理
//注意选择你认为比较好的出错处理方法
#include <stdio.h>
//定义数组最大长度
#define arrsize 15
//计算阶乘
int factorial(int n){
    if (n>0)
    {
       return n*factorial(n-1);
    }
    else{
        return 1;
    }
}
//计算2的n次方
int power_2(int n){
    if (n>0)
    {
        return 2*power_2(n-1);
    }
    else
    {
        return 1;
    }
}

int main(){
    int n;
    printf("输入一个整数");
    scanf("%d",&n);
    if (n<0||n>=arrsize)
    {
        printf("你输入的数据不合法");
        return 0;
    }
    
    int a[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp=factorial(i)*power_2(i);
        a[i]=factorial(i)*power_2(i);
        if (a[i]<a[i-1]&&i!=0)
        {
            printf("此时n>arrsize或对某个k(0=<k<=n-1)使k!*2^k>MAXINT");
            break;
        }
        printf("%d\n",a[i]);
    }
    return 0;
}