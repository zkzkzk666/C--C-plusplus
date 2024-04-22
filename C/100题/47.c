// 输入一行字符统计其中有多少个单词，单词之间用空格分隔开
#include<stdio.h>

int main()
{
    char ch;
    //num为单词的个数
    int num=0;
    printf("请输入一行字符，单词之间用一个空格分隔开\n");
    while ((ch=getchar())!='\n')
    {
        //当碰到空格时，说明上一个单词的字符输出完成，此时单词个数加一
        if (ch==' ')
        {
           num++; 
        }
    }
    //最后一个单词输出后不用空格，直接敲换行，此时num还是需要+1
    printf("该行字符有%d个字符",++num);
    return 0;
}
