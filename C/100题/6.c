// 输入三个数字，求出最大的数字。
#include<stdio.h>


//求三个数字中最大的数字
int max(int a,int b,int c){
    //三元运算符
    return a>=b?(a>=c?a:c):(b>=c?b:c);
}


int main(){
    int a,b,c;
    printf("输入三个数字\n");
    scanf("%d%d%d",&a,&b,&c);
    printf("三个数字中最大的数字为：%d",max(a,b,c));
    return 0;
}