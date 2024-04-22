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

//顺序栈存储空间的初始分配量
#define StackInitSize    10
//顺序栈存储空间每次增加的分配量
#define StackAddSize     10

//定义顺序栈的结构体
typedef struct
{
    int *base;//在栈构造之前和销毁之后，base的值为NULL
    int *top;//栈顶指针
    int StackSize;//当前已分配的存储空间
}SqStack;

//初始化一个空顺序栈 
Status InitStack(SqStack *S);

//销毁一个顺序栈 
Status DestroyStack(SqStack *S);

//清空顺序栈
Status ClearStack(SqStack *S);

//判断顺序栈是否为空
Status EmptyStack(SqStack S);

//判断顺序栈是否已满
Status FullStack(SqStack S);

//求当前顺序栈的长度
int Length(SqStack S);

//插入元素e为新的栈顶元素
Status Push(SqStack *S,int e);

//删除栈顶元素，并用e返回
Status Pop(SqStack *S,int *e);

//打印顺序栈的元素
void PrintfStack(SqStack S);


int main(){
    SqStack S;
    InitStack(&S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Push(&S,9);
    Push(&S,10);
    Push(&S,11);
    printf("%d\n",FullStack(S));
    PrintfStack(S);
    int e;
    Pop(&S,&e);
    printf("删除的元素为%d\n",e);
    PrintfStack(S);
    printf("%d\n",FullStack(S));
    printf("%d\n",EmptyStack(S));
    printf("%d\n",Length(S));
    DestroyStack(&S);
}


//初始化一个空顺序栈 
Status InitStack(SqStack *S){
    //构造一个新的栈
    S->base=(int *)malloc(StackInitSize*(sizeof(int)));//动态分配数组空间
    if(!S->base) exit(OVERFLOW);//存储空间分配失败
    S->top=S->base;//此时为空栈
    S->StackSize=StackInitSize;//初始化后最大容量为StackInitSize
    return OK;
}
//销毁一个顺序栈 
Status DestroyStack(SqStack *S){
    if (S==NULL) exit(OVERFLOW);
    free(S->base);//释放动态开辟的空间
    //将S的属性全部置空
    S->base=NULL;
    S->top=NULL;
    S->StackSize=0;
    return OK;
}
//清空顺序栈
Status ClearStack(SqStack *S){
    //清空栈的的前提是栈要存在
    if (!S->base) exit(OVERFLOW);
    //只需将顺序栈的top指针指向base指针即可清空
    S->top=S->base;
    return OK;
}
//判断顺序栈是否为空
Status EmptyStack(SqStack S){
    //只需判断顺序栈的top指针是否指向base指针
    if (S.base==S.top) return TRUE;
    return FALSE;
}
//判断顺序栈是否已满
Status FullStack(SqStack S){
    return S.top-S.base>=S.StackSize;
}
//求当前顺序栈的长度
int Length(SqStack S){
    return S.top-S.base;
}
//插入元素e为新的栈顶元素
Status Push(SqStack *S,int e){
    if (S->top-S->base>=S->StackSize)
    {
        S->base=(int *)realloc(S->base,(S->StackSize+StackAddSize)*sizeof(int));
        if(!S->base) exit(OVERFLOW);//存储空间分配失败
        S->top=S->base+S->StackSize;
        S->StackSize+=StackAddSize;
    }
    *(S->top)=e;
    S->top++;
    return OK;
}
//删除栈顶元素，并用e返回
Status Pop(SqStack *S,int *e){
    //判断栈是否为空
    if (S->top==S->base)
    {
        printf("此栈为空\n");
        return ERROR;
    }
    *e=*(S->top);
    S->top--;
    return OK;
}
//打印顺序栈的元素
void PrintfStack(SqStack S){
    if (EmptyStack(S))
    {
        printf("此栈为空,不能读取\n");
        exit(OVERFLOW);
    }
    int *p = S.top - 1;
    printf("栈顶\n");
    while (p >= S.base) {
        printf("%d\n", *p);
        p--;
    }
    printf("栈底\n");
}