// 输入字符串，统计字符串中字母，数字，空格，以及其他字符的个数。
#include<stdio.h>

#define MaxSize 64

int main(){
    char str[MaxSize];
    int Alphabet=0,Number=0,Blank=0,Another=0;
    // scanf("%s",&str);不能接受带空格的字符串
    printf("请输入字符串\n");
    gets(str);//gets函数读取换行符之前(不包括换行符)的所有字符，并在这些字符后添加一个空字符(\0)。
    //当读取到空字符时表示读取完成
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]>=48&&str[i]<=57)
        {
            Number++;
        }
        else if ((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
        {
            Alphabet++;
        }
        else if (str[i]==32){
            Blank++;
        }
        else{
            Another++;
        }
    }
    printf("字符串%s中字母为%d个，数字为%d个，空格为%d个，其他字符为%d个",str,Alphabet,Number,Blank,Another);
    return 0;
}