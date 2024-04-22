//三个数比大小并按顺序输出。
#include<stdio.h>

int main(){
    int a,b,c,temp;
    printf("请输入第一个数\n");
    scanf("%d",&a);
    printf("请输入第二个数\n");
    scanf("%d",&b);
    printf("请输入第三个数\n");
    scanf("%d",&c);
    //按照从大到小的顺序输出
    if (a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if (b<c)
    {
        temp=b;
        b=c;
        c=temp;
    }
     if (a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    printf("%d %d %d",a,b,c);
}