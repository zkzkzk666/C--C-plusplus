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

//定义循环双链表的结构体
typedef struct DuLNode
{
    int data;//循环双链表所存储的值
    struct DuLNode *prior,*next;//next指针指向下一个结点,prior指针指向上一个结点
}DuLNode,*DuLinkList;//DuLNode强调是一个结点，DuLinkList强调是一个循环双链表

//初始化一个空的，带头结点的循环双链表
Status InitList(DuLinkList *L);

//判断循环双链表是否为空
Status IsEmptyList(DuLinkList L);

//销毁循环双链表
Status DestroyList(DuLinkList *L);

//清空循环双链表
Status ClearList(DuLinkList L);

//求循环双链表表长,返回值为表长
int LengthList(DuLinkList L);

//头插法建立循环双链表，创建n个元素
Status CreateHeadList(DuLinkList *L,int n);

//尾插法建立循环双链表，创建n个元素
Status CreateTailList(DuLinkList *L,int n);

//获取第i个数据元素,并存入e中
Status GetElemList(DuLinkList L,int i,int *e);

//在循环双链表第i个位置前插入元素e
Status InsertList(DuLinkList L,int i,int e);

//按值查找数据所在地址并返回所查询数据的地址
DuLinkList SearchList(DuLinkList L,int e);

//按值查找数据所在位序并返回
int LocateList(DuLinkList L,int e);

//删除在循环双链表中位序为i的结点
Status DeleteList(DuLinkList L,int i);

//遍历打印循环双链表数据
void PrintList(DuLinkList L);


int main(){
    DuLinkList L;
    printf("%d\n",InitList(&L));
    printf("%d\n",IsEmptyList(L));//是否为空1空0非空
    CreateTailList(&L,2);
    // CreateHeadList(&L,2);头插法
    int e;
    GetElemList(L,2,&e);//获取位序为2的数据
    printf("你所查找的元素为%d\n",e);
    PrintList(L);
    InsertList(L,1,3);//添加一个结点
    PrintList(L);
    printf("你查找元素的地址为%p\n",SearchList(L,3));
    printf("你查找元素的位序为%d\n",LocateList(L,3));
    DeleteList(L,1);//删除一个结点
    PrintList(L);
    printf("%d\n",LengthList(L));
    ClearList(L);
    printf("%d\n",IsEmptyList(L));
    DestroyList(&L);
    printf("%d\n",IsEmptyList(L));
    return 0;
}

//初始化一个空的，带头结点的循环双链表
Status InitList(DuLinkList *L){
    *L=(DuLNode *)malloc(sizeof(DuLNode));//分配一个头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    (*L)->next=*L;//将头节点的前驱指向自己
    (*L)->prior=*L;//将头节点的后继指向自己
    printf("初始化成功\n");
    return OK;
}
//判断循环双链表是否为空
Status IsEmptyList(DuLinkList L){
    //只需判断头节点后继是否是本身
    if (L->next==L)
    {
        printf("当前链表为空\n");
        return TRUE;
    }
    else
    {
        printf("当前链表不为空\n");
        return FALSE;
    }
}
//销毁循环双链表
Status DestroyList(DuLinkList *L){
	DuLinkList p =(*L)->next;
    //free所有的结点包括头结点
	while (p->next!=*L)
	{
		DuLNode* next = p->next;
		free(p);
		p=next;
	}
	free(*L);//free头结点
    printf("销毁成功\n");
    return OK;
}
//清空循环双链表
Status ClearList(DuLinkList L){
    DuLinkList p =L->next;
    //free所有的结点不包括头结点
	while (p!=L)
	{
		DuLNode* next = p->next;
		free(p);
		p=next;
	}
    L->next=L;//将头节点的前驱指向自己
    L->prior=L;//将头节点的后继指向自己
    printf("清空成功\n");
    return OK;
}
//求循环双链表表长,返回值为表长
int LengthList(DuLinkList L){
    DuLinkList p;
    int count=0;//记录表长
    p=L;
    while (p->next!=L)
    {
        count++;
        p=p->next;
    }
    return count;
}
//头插法建立循环双链表，创建n个元素
Status CreateHeadList(DuLinkList *L,int n){
    DuLinkList p,r;//p指向新结点，r指向头节点
    *L=(DuLinkList)malloc(sizeof(DuLNode));//创建头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    r=*L;
    r->next=r;
    r->prior=r;
    for (int i = n; i >0; i--)
    {
        p=(DuLNode *)malloc(sizeof(DuLNode));//生成新的结点
        printf("请输入链表的第%d个元素\n",i);
        scanf("%d",&p->data);
        if (n==1)//只用生成一个结点的情况
        {
            r->next=p;
            p->next=r;
            r->prior=p;
            p->prior=r;
            printf("创建完毕\n");
            return OK;
        }
        //插入到表头
        p->next=r->next;
        r->next->prior=p;
        r->next=p;
        p->prior=r;
    }
    printf("创建完毕\n");
    return OK;
}
//尾插法建立循环双链表，创建n个元素
Status CreateTailList(DuLinkList *L,int n){
    DuLinkList p,r;//p指向新结点,r指向头结点
    *L=(DuLinkList)malloc(sizeof(DuLNode));//创建头结点
    if (*L==NULL)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    r=*L;
    r->next=r;
    r->prior=r;
    for (int i = 0; i <n; i++)
    {
        p=(DuLinkList)malloc(sizeof(DuLNode));//生成新的结点
        if (!p)
        {
            printf("分配内存失败\n");
            exit(OVERFLOW);
        }
        printf("请输入链表的第%d个元素\n",i+1);
        scanf("%d",&p->data);
        if (n==1)
        {
            r->next=p;
            p->next=r;
            r->prior=p;
            p->prior=r;
            printf("创建完毕\n");
            return OK;
        }
        //插入到表尾
        p->next=r;
        p->prior=r->prior;
        r->prior->next=p;
        r->prior=p;
    }
    printf("创建完毕\n");
    return OK;
}
//获取第i个数据元素,并存入e中
Status GetElemList(DuLinkList L,int i,int *e){
    DuLNode *p;
    p=L->next;
    int j=1;
    //通过循环到达第i个元素
    while (p!=L&&j<i)
    {
        p=p->next;
        j++;
    }
    //当i不合法时不能查询
    if (p==L||j>i){
        printf("查询不到该元素\n");
        return ERROR;
    }
    *e=p->data;
    return OK;
}
//在循环双链表第i个位置前插入元素e
Status InsertList(DuLinkList L,int i,int e){
    DuLinkList p,s;//s为新结点
    p=L->next;
    s=(DuLNode *)malloc(sizeof(DuLNode));//建立要插入的结点
    if (!s)
    {
        printf("分配内存失败\n");
        exit(OVERFLOW);
    }
    s->data=e;
    s->next=NULL;//防止脏数据
    s->prior=NULL;
    int j=0;
    //通过循环到达第i-1个元素
    while (p!=L&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==L||j>i-1) {
        printf("插入元素失败\n");
        return ERROR;//当i不合法时不能插入
    }
    p->next->prior=s;
    s->next=p->next;
    s->prior=p;
    p->next=s;
    printf("插入元素成功\n");
    return OK;
}
//按值查找数据所在地址并返回所查询数据的地址
DuLinkList SearchList(DuLinkList L,int e){
    DuLNode *p;
    p=L->next;
    while (p!=L)
    {
        if (p->data==e) return p;
        p=p->next;
    }
    printf("没有找到该数据\n");
    return NULL;
}
//按值查找数据所在位序并返回
int LocateList(DuLinkList L,int e){
    DuLNode *p;
    int j=1;
    p=L->next;
    while (p!=L)
    {
        if (p->data==e) return j;
        p=p->next;
        j++;
    }
    printf("没有找到该数据\n");
    return ERROR;
}
//删除在循环双链表中位序为i的结点
Status DeleteList(DuLinkList L,int i){
    DuLinkList p;
    p=L->next;
    //让p到达位序为i处
    for (int j = 1; p!=L&&j < i; j++)
    {
        p=p->next;
    }
    if (p==L)
    {
        printf("i的值不合法\n");
        return ERROR;
    }
    p->next->prior=p->prior;
    p->prior->next=p->next;
    free(p);
    printf("删除结点成功\n");
    return OK;
}
//遍历打印循环双链表数据
void PrintList(DuLinkList L){
    DuLinkList p=L->next;
    if (p==L)
    {
        printf("链表为空,无法打印\n");
        
    }else{
    printf("双链表为Head");
    }
    while (p!=L)
    {
        printf("<->%d",p->data);
        p=p->next;
    }
    printf("<->Head\n");
}