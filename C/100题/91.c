// 写一个函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度
#include<stdio.h>
//字符串最大长度
#define N 100
int strlen(char *str){
    int i=0;
    //字符串结尾为‘\0’
    while (*str!='\0')
    {
        i++;
        //指针移动到下一个字符
        str++;
    }
    return i;
}


int main(){
    char str[N];
    printf("请输入一个字符串\n");
    gets(str);
    printf("你输入的字符串长度为：%d",strlen(str));
    return 0;
}