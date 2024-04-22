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

//定义队列的结构体
typedef struct QNode
{
    int data;               //队列所存储的值
    struct QNode *next;     //指针指向下一个结点
}QNode,*QueuePtr;           //QNode *强调是一个结点，QueuePtr强调是一个队列

typedef struct 
{
    QueuePtr front;     //队头指针
    QueuePtr rear;      //队尾指针
}LinkQueue;



//初始化一个空的，带头结点的队列
Status InitQueue(LinkQueue *Q);

//判断队列是否为空
Status EmptyQueue(LinkQueue Q);

//销毁队列
Status DestroyQueue(LinkQueue *Q);

//清空队列
Status ClearQueue(LinkQueue *Q);

//求队列长度,返回值为表长
int LengthQueue(LinkQueue Q);

//出队,若队列不为空，则删除队头元素并用e返回其值
Status DeQueue(LinkQueue *Q,int *e);

//入队，插入元素e为Q新的队尾元素
Status EnQueue(LinkQueue *Q,int e);

//遍历打印队列数据
void PrintQueue(LinkQueue Q);


int main(){
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q,1);
    EnQueue(&Q,2);
    EnQueue(&Q,3);
    EnQueue(&Q,4);
    EnQueue(&Q,5);
    PrintQueue(Q);
    printf("%d\n",EmptyQueue(Q));
    printf("此时表长为：%d\n",LengthQueue(Q));
    int a,b,c;
    DeQueue(&Q,&a);
    PrintQueue(Q);
    DeQueue(&Q,&b);
    DeQueue(&Q,&c);
    PrintQueue(Q);
    printf("a:%d\n",a);
    printf("b:%d\n",b);
    printf("c:%d\n",c);
    printf("%d\n",EmptyQueue(Q));
    printf("此时表长为：%d\n",LengthQueue(Q));
    DestroyQueue(&Q);
    return 0;
}


//初始化一个空的，带头结点的队列
Status InitQueue(LinkQueue *Q){
    //分配一个头结点，初始化时头指针和尾指针都指向这个头结点，此时队列为空
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front) exit(OVERFLOW);//存储分配失败
    Q->front->next=NULL;
    printf("初始化成功\n");
    return OK;
}
//判断队列是否为空
Status EmptyQueue(LinkQueue Q){
    return Q.front->next==NULL;//只需判断头指针的下一个结点是否为空
}
//销毁队列
Status DestroyQueue(LinkQueue *Q){
    //需要free所有的结点包括头结点
    while (Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    printf("销毁成功\n");
    return OK;
}
//清空队列
Status ClearQueue(LinkQueue *Q){
    QNode *p=Q->front->next;//跳过队列的头结点
    while (p)
    {
        Q->rear=p->next;
        free(p);
        p=Q->rear;
    }
    Q->front->next=NULL;
    printf("清空成功\n");
    return OK;
}
//求队列长度,返回值为表长
int LengthQueue(LinkQueue Q){
    QNode *p;
    int count=0;//记录表长
    p=Q.front->next;
    while (p)
    {
        count++;
        p=p->next;
    }
    return count;
}
//入队，插入元素e为Q新的队尾元素
Status EnQueue(LinkQueue *Q,int e){
    QNode *p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);//存储分配失败
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return OK;
}
//出队,若队列不为空，则删除队头元素并用e返回其值
Status DeQueue(LinkQueue *Q,int *e){
    if (Q->front->next==NULL)
    {
        printf("队列为空无法出队\n");
        return ERROR;
    }
    QNode *p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    //如果出队的是最后一个元素，需要把头指针和尾指针都指向头结点
    if (Q->rear==p) Q->front=Q->rear;
    //删掉队头结点
    free(p);
    return OK;
}
//遍历打印队列数据
void PrintQueue(LinkQueue Q){
    QNode *p=Q.front->next;
    if (!p)
    {
        printf("队列为空,无法打印\n");
    }else{
    printf("队列为");
    while (p)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
    }
}


