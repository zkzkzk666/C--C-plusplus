//用递归求 n！
#include<stdio.h>

int func(int n){
    if (n==1)
    {
        return 1;
    }
    return n*func(n-1);
}
int main(){
    int n;
    printf("请输入一个整数\n");
    scanf("%d",&n);
    printf("n!为%d",func(n));
    return 0;
}