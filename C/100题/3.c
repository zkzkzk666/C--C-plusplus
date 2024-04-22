//输入年份，判断是否是闰年
#include<stdio.h>

int main(){
    printf("请输入年份：");
    int year;
    scanf("%d",&year);
    //闰年的判断公式：
    //关系一：能被4整除并且不能被100整除
    //关系二：能被400 整除
    if ((year%4==0&&year%100!=0)||year%400==0)
    {
        printf("是闰年");
    }
    else{
        printf("不是闰年");
    }
    return 0;

}