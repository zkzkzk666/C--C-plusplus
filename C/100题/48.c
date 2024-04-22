// 模拟 strcmp 字符串比较函数，实现字符串大小的比较
#include<stdio.h>
//strcmp函数是两个字符串自左向右逐个字符相比（按 ASCII 值大小相比较），直到出现不同的字符或遇 \0 为止，如果字符全部相等，就比较字符串长度，字符串长度也相等时，两个字符串相等
#include<string.h>
//传入两个指向要比较字符串的地址的指针
int my_strcmp(const char *str1,const char *str2){
    //从左到右，用数组的方式得到字符串中的字符
    int i=0;
    //两个字符串自左向右逐个字符相比直到出现遇到\0 
    while (str1[i]!='\0'&&str2[i]!='\0')
    {
        //字符相等时，比较下一个字符
        if (str1[i]==str2[i])
        {
            i++;
            //直接跳出这次循环，不用执行后续代码
            continue;
        }
        else if (str1[i]>str2[i])
        {
            //1代表大于
            return 1;
        }
        else if (str1[i]<str2[i])
        {
            //-1代表小于
            return -1;
        }
    }
    //当两个字符串最后一个字符同时为\0时，此时说明前面字符全部相等，并且两个字符串长度也相等
    if (str1[i]=='\0'&&str2[i]=='\0')
    {
        //0代表相等
        return 0;
    }
    //当某个字符串先出现\0,另外一个字符串不是\0,说明这个字符串的长度小于另外一个字符串，则这个字符串更小
    if (str1[i]=='\0')
    {
        return -1;
    }
    if (str2[i]=='\0')
    {
        return 1;
    }
}
int main()
{
    char str1[]="abc";
    char str2[]="bbc";
    printf("%d\n",my_strcmp(str1,str2));
    printf("%d\n",strcmp(str1,str2));
    return 0;
}
