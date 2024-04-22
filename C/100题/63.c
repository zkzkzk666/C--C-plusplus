// 输入一个字符串，递归将其逆序输出。如输入 LIGHT，则输出 THGIL
#include<stdio.h>
#include<stdlib.h>
//字符串的最大长度
#define N 20

//逆序输出字符串
void func(char *str){
    if (*str=='\0')
    {
        //结尾时直接退出递归
        return;
    }
    func(str+1);
    printf("%c",*str);
    
}
int main(){
    //分配字符串的空间，就是字符串中能有多少个字符
    char *str=(char *) malloc(N * sizeof(char));
    printf("请输入字符串:\n");
    gets(str);
    func(str);
    return 0;
}