// 求斐波那契额数列的前 N 项。
#include<stdio.h>


//求斐波那契数列指定的那一项
int func(int num){
    if (num<=2)
    {
        return 1;
    }
    return func(num-1)+func(num-2);//递归实现
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("斐波那契额数列的第%d项为%d\n",i,func(i));
    }
    return 0;
}