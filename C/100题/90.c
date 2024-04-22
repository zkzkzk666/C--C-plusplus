/* 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人
退出圈子，问最后留下的是原来第几号的那位*/
#include<stdio.h>

//约瑟夫问题
//递推关系f(n)=(f(n-1)+2)\mod n + 1 
int func(int n){
    if (n==1)
    {
        return 1;
    }
    else{
        return (func(n-1)+2)%n+1;
    }
}

int main(){
    int n;
    printf("输入人数n：");
    scanf("%d",&n);
    printf("最后留下的是原来第%d号的那位",func(n));
    return 0;
}