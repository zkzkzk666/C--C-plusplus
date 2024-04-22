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

//定义单链表的结构体
typedef struct LNode
{
    int data;//单链表所存储的值
    struct LNode *next;//指针指向下一个结点
}LNode,*LinkList;//LNode *强调是一共结点，LinkList强调是一个单链表

//初始化一个空的，带头结点的单链表
Status InitList(LinkList *L);

//判断单链表是否为空
Status IsEmptyList(LinkList L);

//销毁单链表
Status DestroyList(LinkList *L);

//清空单链表
Status ClearList(LinkList L);

//求单链表表长,返回值为表长
int LengthList(LinkList L);

//头插法建立单链表，创建n个元素
Status CreateHeadList(LinkList *L,int n);

//尾插法建立单链表，创建n个元素
Status CreateTailList(LinkList *L,int n);

//获取第i个数据元素,并存入e中
Status GetElemList(LinkList L,int i,int *e);

//在单链表第i个位置前插入元素e
Status InsertList(LinkList L,int i,int e);

//按值查找数据所在地址并返回所查询数据的地址
LinkList SearchList(LinkList L,int e);

//按值查找数据所在位序并返回
int LocateList(LinkList L,int e);

//删除在链表中位序为i的结点
Status DeleteList(LinkList L,int i);

//遍历打印单链表数据6
void PrintList(LinkList L);

//合并两个有序链表A,B为一个有序链表C
Status MergeList(LinkList A,LinkList B,LinkList *C);

int main(){
    LinkList L;
    LinkList L1;
    printf("%d\n",InitList(&L));
    printf("%d\n",IsEmptyList(L));
    // CreateHeadList(&L1,4);//头插法
    CreateTailList(&L1,6);//尾插法
    printf("表长为%d\n",LengthList(L1));
    PrintList(L1);
    int e;
    GetElemList(L1,2,&e);
    printf("你所查找的元素为%d\n",e);
    InsertList(L1,1,6);//添加一个结点
    printf("你查找元素的地址为%p\n",SearchList(L1,3));
    printf("你查找元素的位序为%d\n",LocateList(L1,3));
    DeleteList(L1,6);//删除一个结点
    PrintList(L1);
    printf("%d\n",IsEmptyList(L1));
    ClearList(L1);
    PrintList(L1);
    DestroyList(&L1);
    printf("-----------\n");
    printf("-----------\n");
    printf("-----------\n");
    //测试合并函数功能
    LinkList A,B,C;
    InitList(&C);
    CreateTailList(&A,4);
    CreateTailList(&B,4);
    MergeList(A,B,&C);
    printf("合并后的链表C为");
    PrintList(C);
    return 0;
}
//初始化一个空的，带头结点的单链表
Status InitList(LinkList *L){
    *L=(LNode *)malloc(sizeof(LNode));//分配一个头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    (*L)->next=NULL;//将头节点的后继置空
    return OK;
}
//判断单链表是否为空
Status IsEmptyList(LinkList L){
    //只需判断头节点是否有后继
    if (L->next==NULL)
    {
        printf("当前单链表为空\n");
        return TRUE;
    }
    else
    {
        printf("当前单链表不为空\n");
        return FALSE;
    }
}
//销毁单链表
Status DestroyList(LinkList *L){
    LinkList p=*L;
    //free所有的结点包括头结点
    while (*L)
    {
        *L=(*L)->next;
        free(p);
        p=*L;
    }
    printf("链表已销毁\n");
    return OK;
}
//清空单链表
Status ClearList(LinkList L){
    //free所有结点，不包括头结点
    LinkList p,q;
    p=L->next;
    //p为NULL时说明链表已经全部清空
    while (p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    //头结点指向NULL，此时链表为空表
    L->next=NULL;
    printf("链表已清空\n");
    return OK;
}
//求单链表表长,返回值为表长
int LengthList(LinkList L){
    LinkList p;
    int count=0;//记录表长
    p=L->next;
    while (p)
    {
        count++;
        p=p->next;
    }
    return count;
}
//头插法建立单链表，创建n个元素
Status CreateHeadList(LinkList *L,int n){
    LinkList p,r;//p指向新结点，r指向头节点
    *L=(LinkList)malloc(sizeof(LNode));//创建头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    r=*L;
    r->next=NULL;//避免脏数据
    for (int i = n; i >0; i--)
    {
        p=(LNode *)malloc(sizeof(LNode));//生成新的结点
        printf("请输入链表的第%d个元素\n",i);
        scanf("%d",&p->data);
        //插入到表头
        p->next=NULL;//避免脏数据
        p->next=r->next;
        r->next=p;
    }
    printf("创建完毕\n");
    return OK;
}
//尾插法建立单链表，创建n个元素
Status CreateTailList(LinkList *L,int n){
    LinkList p,r;//p指向新结点,r指向链表尾部结点
    *L=(LinkList)malloc(sizeof(LNode));//创建头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    r=*L;
    r->next=NULL;
    for (int i = 0; i <n; i++)
    {
        p=(LinkList)malloc(sizeof(LNode));//生成新的结点
        if (!p)
        {
            printf("分配内存失败\n");
            exit(OVERFLOW);
        }
        printf("请输入链表的第%d个元素\n",i+1);
        scanf("%d",&p->data);
        //插入到表尾
        p->next=NULL;//避免脏数据
        r->next=p;
        r=r->next;//将尾部指针移向新的结点p，然后p就变成新的尾部结点
    }
    r->next=NULL;
    printf("创建完毕\n");
    return OK;
}
//获取第i个数据元素,并存入e中
Status GetElemList(LinkList L,int i,int *e){
    LNode *p;
    p=L->next;
    int j=1;
    //通过循环到达第i个元素
    while (p&&j<i)
    {
        p=p->next;
        j++;
    }
    //当i不合法时不能查询
    if (!p||j>i){
        printf("查询不到该元素\n");
        return ERROR;
    }
    *e=p->data;
    return OK;
}
//在单链表第i个位置前插入元素e
Status InsertList(LinkList L,int i,int e){
    LinkList p,s;
    p=L;//指向头结点
    s=(LNode *)malloc(sizeof(LNode));//建立要插入的结点
    if (!s)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    s->data=e;
    s->next=NULL;
    int j=0;
    //通过循环到达第i-1个元素
    while (p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return ERROR;//当i不合法时不能插入
    s->next=p->next;
    p->next=s;
    printf("插入元素成功\n");
    return OK;
}
//按值查找数据所在地址并返回所查询数据的地址
LinkList SearchList(LinkList L,int e){
    LNode *p;
    p=L->next;
    while (p)
    {
        if (p->data==e) return p;
        p=p->next;
    }
    printf("没有找到该数据\n");
    return NULL;
}
//按值查找数据所在位序并返回
int LocateList(LinkList L,int e){
    LNode *p;
    int j=1;
    p=L->next;
    while (p)
    {
        if (p->data==e) return j;
        p=p->next;
        j++;
    }
    printf("没有找到该数据\n");
    return ERROR;
}
//删除在链表中位序为i的结点
Status DeleteList(LinkList L,int i){
    LinkList p,q;
    p=L;
    //让p到达位序为i-1处
    for (int j = 0; p&&j < i-1; j++)
    {
        p=p->next;
    }
    q=p->next;//q为被删除的结点
    if (!q)
    {
        printf("i的值不合法\n");
        return ERROR;
    }
    p->next=q->next;
    free(q);
    printf("删除成功\n");
    return OK;
}
//遍历打印单链表数据
void PrintList(LinkList L){
    LinkList p=L->next;
    if (!p)
    {
        printf("链表为空,无法打印\n");
        
    }else{
    printf("单链表为Head");
    }
    while (p)
    {
        printf("->%d",p->data);
        p=p->next;
    }
    printf("\n");
}
//合并两个有序链表A,B为一个有序链表C
Status MergeList(LinkList A, LinkList B, LinkList *C) {
    LNode *pa;
    LNode *pb;
    LNode *pc;
    pa = A->next;
    pb = B->next;
    pc =*C;//pc为遍历和操作链表 C 的指针
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pc->next;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
    }
    //插入剩余段
    if (pa != NULL) pc->next = pa;
    if (pb != NULL) pc->next = pb;
    free(B);
    printf("合并成功\n");
    return OK;
}
