// 求斐波那契数列的指定一项。（斐波那契数列举例：1，1，2，3，5，8，13…）
#include<stdio.h>

int func(int num){
    if (num<=2)
    {
        return 1;
    }
    return func(num-1)+func(num-2);//递归实现
}

int main(){
    int num,ret;
    printf("输入你想指定的项数\n");
    scanf("%d",&num);
    ret=func(num);
    printf("斐波那契数列第%d项为%d",num,ret);
    return 0;
}