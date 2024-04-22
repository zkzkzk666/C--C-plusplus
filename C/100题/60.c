/*编一个程序，将两个字符串 s1 和 s2 比较，若 s1>s2，输出一个正数；若 s1=s2，
输出 0；若 s1<s2，输出一个负数。不要用 strcpy 函数。两个字符串用 gets 函数
读入。输出的正数或负数的绝对值应是相比较的两个字符串相应字符的 ASCII 码的差
值。例如，"A"与 C”相比，由于"A<C”，应输出负数，同时由于’A'与 C’的 ASCII 
码差值为 2，因此应输出“-2”。同理："And”和"Aid"比较，根据第 2 个字符比较结
果，“n”比 i”大 5，因此应输出“5”。*/
#include<stdio.h>
//定义数组的长度
#define N 10

int my_strcmp(char *str1,char *str2){
    //创建一个i同时指向两个数组下标
    int i=0;
    //当字符相差为0时且两个字符不同时为'\0'(字符串结尾)，此时两个字符相等，i++，移动到下一个字符继续比较
    while ((str1[i]-str2[i])==0&&(str1[i]!='\0'||str2[i]!='\0'))
    {
        i++;
    }
    //直接返回ASCII码差值，同时为'\0'时，两个字符串相等，差值为0，也可以直接返回
    return str1[i]-str2[i];
}
int main()
{
    //创建两个字符数组
    char str1[N];
    char str2[N];
    printf("请输入字符串str1\n");
    gets(str1);
    printf("请输入字符串str2\n");
    gets(str2);
    printf("%d",my_strcmp(str1,str2));
    return 0;
}
