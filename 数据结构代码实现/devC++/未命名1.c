//输入十个数求其中最大的数字。
#include<stdio.h>

int main(){
    int max=0,num;
    for (int i = 0; i < 10; i++)
    {
        printf("请输入第%d个数\n",i+1);
        scanf("%d",&num);
        if (num>=max)
        {
            max=num;
        }
    }
    printf("其中最大的数为%d",max);
    return 0;
}
