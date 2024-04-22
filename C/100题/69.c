// 输入一个表示星期几的数，然后输出相应的英文单词，要求使用指针数组实现
#include<stdio.h>

//指针数组就是数组中每个元素都是指针
int main(){
    //初始化七个字符常量，代表星期几,const修饰表示这是字符串常量，不可以修改
    const char *str1="Monday";
    const char *str2="Tuesday";
    const char *str3="Wednesday";
    const char *str4="Thursday";
    const char *str5="Friday";
    const char *str6="Saturday";
    const char *str7="Sunday";
    //定义一个指针数组，该数组中，每个元素都是指向一个字符串的指针，也代表着这个字符串的地址
    const char **str[7]={&str1,&str2,&str3,&str4,&str5,&str6,&str7};
    int n;
    printf("请输入数字1到7中的一个：");
    scanf("%d",&n);
    if (n>=0&&n<=7)
    {
        printf("%s",*str[n-1]);
    }
    else{
        printf("只能输入数字1-7");
    }
    return 0;
}