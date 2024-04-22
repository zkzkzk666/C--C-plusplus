// 给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
#include<stdio.h>

int main(){
    int num;
    int len=0;
    printf("请输入一个不多于5位的正整数:");
    scanf("%d",&num);
    while (num>0)
    {
        printf("%d",num%10);
        num/=10;
        len++;
    }
    printf("\n它是%d位数",len);
    
    return 0;
}