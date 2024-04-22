// 输出一行文字中最长单词
#include<stdio.h>

#define N 20

int main(){
    char str[N];
    printf("请输入一行文字\n");
    gets(str);
    //最长字符串的长度
    int max=0;
    //str数组的下标
    int i=0;
    //记录最长字符串在数组中的位置
    int flag=0;
    //记录每个单词的长度
    int temp=0;
    //循环条件，不能超过数组下标，遇到换行或者字符串尾就停止循环
    while (i < N && str[i] != '\0' && str[i] != '\n') {
        //每个单词以空格分隔
        if (str[i] != ' ') {
            temp++;
        } else {
            //遇到空格说明单词长度记录完成，可以进行比较
            if (temp > max) {
                //存储最大的单词长度
                max = temp;
                //记录最大长度单词在字符串中的位置
                flag = i - temp;
            }
            temp = 0; // 重置 temp 为0，准备计算下一个单词的长度
        }
        i++;
    }
    //因为最后一个单词没有以空格结尾，所以最后一个单词还要继续进行比较
    if (temp > max) {
        max = temp;
        flag = i - temp;
    }
    //打印单词
    for (int j = 0; j < max; j++)
    {
        printf("%c",str[flag+j]);
    }
    return 0;
}