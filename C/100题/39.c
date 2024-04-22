//给出年月日，计算该日是该年的第几天
#include<stdio.h>

//判断次年份是否是闰年
//闰年的判断公式：
//关系一：能被4整除并且不能被100整除
//关系二：能被400 整除
int isLeapYear(int year){
    if ((year%4==0&&year%100!=0)||year%400==0)
    {
        //是闰年
        return 1;
    }
    else{
        //不是闰年
        return 0;
    }
}
int main()
{
    int year,month,day;
    //创建每月有多少天的数组
    int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("请输入年:\n");
    scanf("%d",&year);
    printf("请输入月:\n");
    scanf("%d",&month);
    printf("请输入日:\n");
    scanf("%d",&day);
    int sum=day;
    for (int i = 0; i < month-1; i++)
    {
        sum+=month_day[i];
    }
    //如果是闰年并且月份大于二就要加上二月多出的一天
    if (isLeapYear(year)&&month>2)
    {
        sum+=1;
    }
    printf("%d年%d月%d日是该年的第%d天",year,month,day,sum);
    return 0;
}
