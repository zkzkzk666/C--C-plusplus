// 输入 n 个字符串，把其中以字母 A 打头的字符串输出。
#include<stdio.h>
#include<stdlib.h>
//字符串的最大长度
#define N 20

int main(){
    int n;
    printf("请输入字符串个数n:");
    scanf("%d",&n);
    //读取缓冲区的回车字符
    getchar();
    //动态分配空间存储字符串数组，就是分配有n个字符串的数组
    char **str=(char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        //分配数组中每个字符串的空间，就是字符串中能有多少个字符
        str[i]=(char *) malloc(N * sizeof(char));
        printf("请输入第%d个字符串\n",i+1);
        gets(str[i]);
    }
    printf("字母A打头的字符串为：\n");
    for (int j = 0; j < n; j++)
    {
        if (str[j][0]=='A')
        {
            printf("%s\n",str[j]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        //先释放字符串所占的空间
        free(str[j]);
    }
    //最后释放字符串数组占用的空间
    free(str);
    return 0;
}