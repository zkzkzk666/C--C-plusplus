#include <stdio.h>
#include <stdlib.h>
//函数结果状态代码
#define TRUE         1
#define FALSE        0
#define OK           1
#define ERROR        0
#define INFEASIBLE  -1
#define OVERFLOW    -2

//给int定义别名为status，当函数返回值是为状态码时，可用status作为函数类型，更方便理解
typedef int Status;

//定义串的结构体，采用动态分配的链式存储结构
typedef struct
{
    char *ch;//若是非空串根据串长分配存储空间，否则ch为NULL
    int length;//串的长度
}HString;


//初始化生成一个空串
Status InitStr(HString *S);

//生成一个其值等于串常量chars的串T
Status AssignStr(HString *T,char *chars);

//由串S复制得串T
Status CopyStr(HString S,HString *T);
//判断串S是否为空串
Status EmptyStr(HString S);

//返回串S的元素个数，称为串的长度
int LengthStr(HString S);

//比较串S与串T的大小，S>T，返回值大于零，S=T，返回值等于零，S<T,返回值小于零
int CompareStr(HString S,HString T);

//将串S清为空串，并释放所占空间
Status ClearStr(HString S);

//销毁串S
Status DestroyStr(HString *S);

//用串T返回由串S1和串S2联接而成的新串
Status ConcatStr(HString *T,HString S1,HString S2);

//用串Sub返回串S的第pos个字符起长度为len的子串
Status SubStr(HString *Sub,HString S,int pos,int len);

//在串S的第pos个字符前插入串T
Status InsertStr(HString *S,int pos,HString T);

//从串S中删除第pos个字符起长度为len的子串
Status DeleteStr(HString *S,int pos,HString T);

//用串V替换主串S中出现的所有与串T相等的不重叠的子串
Status ReplaceStr(HString *S,HString T,HString V);

//串的模式匹配,返回值为第一次出现的位置
int IndexStr(HString S,HString T,int pos);

int main(){
    HString str;
    HString str1;
    InitStr(&str1);
    printf("%d\n",EmptyStr(str1));

    char chars[] = "Hello, World!";

    AssignStr(&str, chars);
    printf("%d\n",EmptyStr(str));
    printf("str.ch = %s\n", str.ch);
    printf("str.length = %d\n", str.length);
    free(str.ch);
    free(str1.ch);
}
//初始化生成一个空串
Status InitStr(HString *S){
    if (S->ch) 
    {
        free(S->ch);//释放S原有空间
        S->ch=NULL;
    }
    S->length=0;
    return OK;
}
//生成一个其值等于串常量chars的串S
Status AssignStr(HString *S,char *chars){
    if (S->ch) free(S->ch);
    //求chars的长度i
    int i;
    for (i = 0; chars[i] != '\0'; i++);
    if (!i)
    {
        //i为0时，chars为空串，将S也变成空串即可
        S->ch=NULL;
        S->length=0;
        return OK;
    }
    else
    {
        // 给S分配合适的空间,注意要多分配一个字节来存储空字符 '\0'
        S->ch = (char*)malloc((i + 1) * sizeof(char));  
        if (!S->ch)
            exit(OVERFLOW);
        for (int j = 0; j < i; j++) {
            S->ch[j] = chars[j];  // 逐个字符复制
        }
        // 添加字符串结束符 '\0'
        S->ch[i] = '\0';  
        S->length = i;
        return OK;
    }
}
//判断串S是否为空串
Status EmptyStr(HString S){
    if (S.length==0)
    {
        return 1;
    }
    return 0;
}
//返回串S的元素个数，称为串的长度
int LengthStr(HString S){
    return S.length;
}
