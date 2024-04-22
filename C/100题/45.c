// 用递归求正整数 a 和 b 最大公约数。
#include<stdio.h>

//求最大公约数这里采用的是辗转相除法，也叫欧几里德算法

int func(int a,int b){
    //当a取模b为零是说明b就是a的最大公约数
    if (a%b==0)
    {
        return b;
    }
    //其他情况时，将a替换为b，b替换为a%b继续继续辗转相除
    //b>a时，这一步也可以将它们互换,此时a%b=a,即func(a,b)-->func(b,a)然后再继续辗转相除
    return func(b,a%b);
}


int main()
{
    int a,b;
    printf("请输入正整数a\n");
    scanf("%d",&a);
    printf("请输入正整数b\n");
    scanf("%d",&b);
    printf("%d与%d的最大公约数是%d",a,b,func(a,b));
    return 0;
}
