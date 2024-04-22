// 把一个字符串插到另一个字符串中的指定位置
#include<stdio.h>
#include<stdlib.h>
//字符串的最大长度为10
#define N 10

int main(){
    //把str2插入到str1中
    char *str1=(char *)malloc(N*sizeof(char));
    char *str2=(char *)malloc(N*sizeof(char));
    printf("输入字符串str1\n");
    gets(str1);
    printf("输入字符串str2\n");
    gets(str2);
    //指定要插入的位置，要小于等于str1的长度
    int n;
    printf("输入你想把str2插入到str1中的位置n：");
    scanf("%d",&n);
    //str2的长度
    int length=0;
    while (str2[length]!='\0')
    {
        length++;
    }
    //插入后形成的字符串str3
    char *str3=(char *)malloc((N+length+1)*sizeof(char));
    
    //循环给str3赋值
    for (int i = 0; i < N+length; i++)
    {
        //没有到插入位置之前就是str1的部分
        if (i<n)
        {
            str3[i]=str1[i];
        }
        //到了插入位置时，就应该插入str2
        else if (i<n+length)
        {
            str3[i]=str2[i-n];
        }
        //如果str1有剩余部分，就给加上去
        else{
            str3[i]=str1[i-length];
        } 
    }
    str3[N + length] = '\0'; 
    printf("%s\n",str3);
    free(str1);
    free(str2);
    free(str3);
    return 0;
}