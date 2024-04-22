/*输出所有的水仙花数。水仙花数字是指一个三位数字，其各个位置数字的立方和等于其
本身。*/
#include<stdio.h>

int main(){
    for (int i = 100; i < 1000; i++)
    {
        int a=i/100;//百位
        int b=i%100/10;//十位
        int c=i%100%10;//个位
        if ((a*a*a+b*b*b+c*c*c)==i)
        {
            printf("%d\n",i);
        }
    }
}