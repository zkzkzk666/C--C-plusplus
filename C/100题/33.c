// 输入一个英文句子，以‘ . ’结束，统计句子中包含的字符个数
#include<stdio.h>

int main(){
    char ch;
    int length=0;
    printf("请输入一个英文句子\n");
    while (ch=getchar()!='.')
    {
        length++;
    }
    printf("字符个数是：%d",length);
    return 0;
}