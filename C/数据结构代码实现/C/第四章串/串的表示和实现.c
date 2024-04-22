#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//给int定义别名为status，当函数返回值是为状态码时，可用status作为函数类型，更方便理解
typedef int Status;

//定义串的结构体，采用动态分配的链式存储结构
typedef struct
{
    char *ch;//若是非空串根据串长分配存储空间，否则ch为NULL
    int length;//串的长度
}HString;

//生成一个其值等于串常量chars的串T
Status AssignStr(HString *T,char *chars);

//由串S复制得串T
Status CopyStr(HString T,HString *S);

//判断串S是否为空串
Status EmptyStr(HString S);

//返回串S的元素个数，称为串的长度
int LengthStr(HString S);

//比较串S与串T的大小，S>T，返回值大于零，S=T，返回值等于零，S<T,返回值小于零
int CompareStr(HString S,HString T);

//将串S清为空串，并释放所占空间
Status ClearStr(HString *S);

//用串T返回由串S1和串S2联接而成的新串
Status ConcatStr(HString *T,HString S1,HString S2);

//用串Sub返回串S的第pos个字符起长度为len的子串
Status SubStr(HString *Sub,HString S,int pos,int len);

//在串S的第pos个字符前插入串T
Status InsertStr(HString *S,int pos,HString T);

//从串S中删除第pos个字符起长度为len的子串(包括第pos个字符)
Status DeleteStr(HString *S,int pos,int len);

//用串V替换主串S中出现的所有与串T相等的不重叠的子串
Status ReplaceStr(HString *S,HString T,HString V);

//串的模式匹配,返回值为第一次出现的位置,其中子串为T,主串为S
int IndexStr(HString S,HString T,int pos);

//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法，返回值为第一次出现的位置
int KMP_IndexStr(HString S, HString T, int pos,int next[]);

//求模式串T的next的函数值并存入数组next
void GetNext(HString T,int next[]);

int main(){
    // HString str1,str2;
    // HString T;
    // HString Sub;
    // char chars1[]="Hello,World!";
    // char chars2[]="ll";
    // char chars3[]="Helll,World!";
    // //给三个串赋值
    // AssignStr(&str1,chars1);
    // AssignStr(&str2,chars2);
    // AssignStr(&T,chars3);
    // printf("str1.ch = %s\n", str1.ch);
    // printf("str1.length = %d\n",LengthStr(str1));
    // printf("str2.ch = %s\n", str2.ch);
    // printf("str2.length = %d\n",LengthStr(str2));
    // printf("T.ch = %s\n", T.ch);
    // printf("T.length = %d\n", LengthStr(T));
    // printf("T是否为空:%d\n",EmptyStr(T));

    // printf("比较str1与T大小:%d\n",CompareStr(str1,T));

    // //联接str1和str2为T
    // ConcatStr(&T,str1,str2);
    // printf("T.ch = %s\n", T.ch);
    // printf("T.length = %d\n", LengthStr(T));
    // printf("T是否为空:%d\n",EmptyStr(T));

    // //把str2的值复制给T
    // CopyStr(str2,&T);
    // printf("------------------\n");
    // printf("T.ch = %s\n", T.ch);
    // printf("T.length = %d\n", LengthStr(T));

    // //用串Sub返回串str的第7个字符起长度为5的子串
    // SubStr(&Sub, str1,7,5);
    // printf("Sub.ch = %s\n", Sub.ch);
    // printf("Sub.length = %d\n", LengthStr(Sub));
    // printf("Sub是否为空:%d\n",EmptyStr(Sub));

    // //在串Sub的第2个字符前插入串str2
    // InsertStr(&Sub,2,str2);
    // printf("插入后Sub.ch = %s\n", Sub.ch);
    // printf("插入后Sub.length = %d\n", LengthStr(Sub));
    // //删除串Sub的第1个字符
    // DeleteStr(&Sub,1,1);
    // printf("删除后Sub.ch = %s\n", Sub.ch);
    // printf("删除后Sub.length = %d\n", LengthStr(Sub));

    // printf("------------------\n");
    // //将str1与T进行匹配，str1为主串，T为子串
    // printf("T.ch = %s\n", T.ch);
    // printf("T.length = %d\n", LengthStr(T));
    // printf("str1.ch = %s\n", str1.ch);
    // printf("str1.length = %d\n",LengthStr(str1));
    // printf("第一次出现的位置为%d\n", IndexStr(str1,T,1));

    // //用串Sub替换主串str1中出现的所有与串T相等的不重叠的子串
    // printf("Sub.ch = %s\n", Sub.ch);
    // printf("Sub.length = %d\n", LengthStr(Sub));
    // ReplaceStr(&str1,T,Sub);
    // printf("str1.ch = %s\n", str1.ch);
    // printf("str1.length = %d\n",LengthStr(str1));

    // //清空串T
    // ClearStr(&T);
    // printf("------------------\n");
    // printf("T.ch = %s\n", T.ch);
    // printf("T.length = %d\n", LengthStr(T));
    // printf("T是否为空:%d\n",EmptyStr(T));

    printf("------------------\n");
    printf("------------------\n");
    printf("------------------\n");
    printf("------------------\n");
    printf("------------------\n");
    printf("------------------\n");

    HString S, T;
    AssignStr(&S, "ABCDABDABDABCDCABCDABCDABDE");
    AssignStr(&T, "ABCDABD");
    printf("T.ch = %s\n", T.ch);
    printf("T.length = %d\n", LengthStr(T));
    printf("S.ch = %s\n", S.ch);
    printf("S.length = %d\n",LengthStr(S));
    int next[T.length + 1];
    GetNext(T, next);
    for (int i = 1; i < T.length+1; i++)
    {
        printf("%d ",next[i]);
    }
    int pos = KMP_IndexStr(S, T, 0, next);
    if (pos != -1) {
        printf("Pattern found at position: %d\n", pos);
    } else {
        printf("Pattern not found.\n");
    }
    free(S.ch);
    free(T.ch);
    return 0;
}

//生成一个其值等于串常量chars的串T
Status AssignStr(HString* T, char* chars)
{
    int len = 0;
    //求出串chars的长度
    while (chars[len] != '\0')
        len++;

    //多分配一个字节来存储空字符'\0'
    T->ch = (char*)malloc((len + 1) * sizeof(char));
    if (!T->ch)
        exit(OVERFLOW);
    //chars中最后一个字符为'\0',在循环中已经添加复制到T中去了
    for (int i = 0; i <= len; i++)
        T->ch[i] = chars[i];
    T->length = len;
    return OK;
}
//由串S复制得串T
Status CopyStr(HString S, HString* T)
{
    T->ch = (char*)malloc((S.length + 1) * sizeof(char));
    if (!T->ch)
        exit(OVERFLOW);
    
    for (int i = 0; i <= S.length; i++)
        T->ch[i] = S.ch[i];
    
    T->length = S.length;
    return OK;
}
//判断串S是否为空串
Status EmptyStr(HString S)
{
    if (S.length == 0)
        return TRUE;
    else
        return FALSE;
}
//返回串S的元素个数，称为串的长度
int LengthStr(HString S)
{
    return S.length;
}
//比较串S与串T的大小，S>T，返回值大于零，S=T，返回值等于零，S<T,返回值小于零
int CompareStr(HString S, HString T)
{
    for (int i = 0; i < S.length && i < T.length; i++)
    {
        if (S.ch[i] < T.ch[i])
            return -1;
        else if (S.ch[i] > T.ch[i])
            return 1;
    }
    //如果循环遍历结束前不能判断两串的大小，就比较两串的长度
    if (S.length < T.length)
        return -1;
    else if (S.length > T.length)
        return 1;
    return 0;
}
//将串S清为空串，并释放所占空间
Status ClearStr(HString* S)
{
    if (S->ch)
    {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
    return OK;
}
//用串T返回由串S1和串S2联接而成的新串
Status ConcatStr(HString* T, HString S1, HString S2)
{
    T->ch = (char*)malloc((S1.length + S2.length + 1) * sizeof(char));
    if (!T->ch)
        exit(OVERFLOW);
    for (int i = 0; i < S1.length; i++)
        T->ch[i] = S1.ch[i];
    //i <= S2.length这里加等于号是因为要把S2中的'\0'添加到T中
    for (int i = 0; i <= S2.length; i++)
        T->ch[S1.length + i] = S2.ch[i];
    T->length = S1.length + S2.length;
    return OK;
}
//用串Sub返回串S的第pos个字符起长度为len的子串
Status SubStr(HString* Sub, HString S, int pos, int len)
{
    //判断pos与len的值是否合法，S.length - pos并没有算上第pos个字符，所以在判断时要再加上1
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return ERROR;
    Sub->ch = (char*)malloc((len + 1) * sizeof(char));
    if (!Sub->ch)
        exit(OVERFLOW);
    for (int i = 0; i < len; i++)
        Sub->ch[i] = S.ch[pos - 1 + i];
    Sub->ch[len] = '\0';
    Sub->length = len;
    return OK;
}
//在串S的第pos个字符前插入串T
Status InsertStr(HString* S, int pos, HString T)
{
    if (pos < 1 || pos > S->length + 1)
        return ERROR;
    //重新分配存储空间
    S->ch = (char*)realloc(S->ch, (S->length + T.length + 1) * sizeof(char));
    if (!S->ch)
        exit(OVERFLOW);
    //把第pos个字符及之后的字符往后移动T.length位
    for (int i = S->length - 1; i >= pos - 1; i--)
        S->ch[i + T.length] = S->ch[i];
    //在第pos个字符前插入串T
    for (int i = 0; i < T.length; i++)
        S->ch[pos - 1 + i] = T.ch[i];
    S->length += T.length;
    return OK;
}
//从串S中删除第pos个字符起长度为len的子串(包括第pos个字符)
Status DeleteStr(HString* S, int pos, int len)
{
    if (pos < 1 || pos >= S->length || len <= 0 || len > S->length - pos + 1)
        return ERROR;
    //将串S第pos+len个字符后的字符往前移len位
    //因为i < S->length，并非<=,所以不能添加'\0'
    for (int i = pos - 1 + len; i < S->length; i++)
        S->ch[i - len] = S->ch[i];
    S->ch = (char*)realloc(S->ch, (S->length - len + 1) * sizeof(char));
    if (!S->ch)
        exit(OVERFLOW);
    S->length -= len;
    //最后添加'\0'为串的结束
    S->ch[S->length] = '\0';
    return OK;
}
//串的模式匹配,返回值为第一次出现的位置,其中子串为T,主串为S
int IndexStr(HString S, HString T, int pos)
{
    //T.length > S.length - pos + 1如果T的长度比要比需要进行匹配的剩余字符的长度长，那就不可能匹配成功
    if (pos < 1 || pos > S.length || T.length > S.length - pos + 1)
        return -1;
    //i相当于指向串S的指针，j相当于指向串T的指针
    int i = pos - 1;
    int j = 0;
    while (i < S.length && j < T.length)
    {
        //继续比较后继字符
        if (S.ch[i] == T.ch[j])
        {
            //如果相等，两串的指针都后移继续比较
            i++;
            j++;
        }
        else
        {
            //如果不相等，串S的指针后移至其本轮匹配开始时i的位置的后一位，串T的指针回到其第一个字符
            i = i - j + 1;
            j = 0;
        }
    }
    //j >= T.length表示全部匹配成功，就返回成功这次i开始匹配的位置
    if (j >= T.length)
        return i - T.length + 1;
    else
        return INFEASIBLE;
}
//用串V替换主串S中出现的所有与串T相等的不重叠的子串
Status ReplaceStr(HString* S, HString T, HString V)
{
    //先找出串T第一次出现的位置
    int index = IndexStr(*S, T, 1);
    //然后对该位置的串进行替换(先删除再插入)
    while (index > 0)
    {
        DeleteStr(S, index, T.length);
        InsertStr(S, index, V);
        //替换后，再找串T在串S中下一个出现的位置
        index = IndexStr(*S, T, index + 1);
    }
    return OK;
}
//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法，返回值为第一次出现的位置
int KMP_IndexStr(HString S, HString T, int pos,int next[]){
    int i=pos;
    int j=0;
    while (i<=S.length&&j<=T.length)
    {
        if (j==0||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else{
            j=next[j];
        }  
    }
    if (j>T.length)
    {
        return i-T.length;
    }
    return INFEASIBLE;
}
//求模式串T的next的函数值并存入数组next
void GetNext(HString T, int next[]) {
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            if (T.ch[i] != T.ch[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }
}