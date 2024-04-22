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

//线性表存储空间的初始分配量
#define listInitSize    10
//线性表存储空间每次增加的分配量
#define listAddSize     10

//定义顺序表的结构体
typedef struct
{
    int* data;//动态分配
    int length;//数据占据当前线性表的长度
    int listSize;//当前线性表的存储容量
}SqList;

//初始化一个空顺序表 
Status InitList(SqList *L);

//销毁一个顺序表 
Status DestroyList(SqList *L);

//清空表
Status ClearList(SqList *L);

//判断顺序表是否为空
Status IsEmptyList(SqList L);

//求当前线性表的长度
int Length(SqList L);

//检查存储容量是否足够，不够的话要增加
void CheckBase(SqList *L);

//在第i个元素之前插入一个元素e
Status InsertList(SqList *L,int i,int e);

//删除表中第i个元素
Status DeleteList(SqList *L,int i,int *e);

//修改表中第i个元素为e
Status UpdateList(SqList *L,int i,int e);

//打印顺序表的元素
void PrintfList(SqList L);

//尾插元素e
Status PushBackList(SqList *L,int e);

//尾删元素
Status DeleteBackList(SqList *L);

//按值查找,返回值为顺序表中的第几个元素
int LocateList(SqList L,int e);

//按位查找,查找顺序表中第i位元素，返回值为查找元素的值
int GetElem(SqList L,int i);

//合并两个顺序表,将顺序表A和顺序表B合并为顺序表C
void MergeList(SqList A,SqList B,SqList *C);


int main(){
    SqList L;
    InitList(&L);
    PushBackList(&L,1);
    PushBackList(&L,2);
    PushBackList(&L,3);
    PushBackList(&L,4);
    PushBackList(&L,5);
    PushBackList(&L,6);
    PushBackList(&L,7);
    PushBackList(&L,8);
    PushBackList(&L,9);
    PushBackList(&L,10);
    PushBackList(&L,11);
    PushBackList(&L,12);
    PushBackList(&L,13);
    PrintfList(L);
    printf("当前表长为%d\n",Length(L));
    printf("插入一个元素后\n");
    InsertList(&L,6,666);
    printf("当前表长为%d\n",Length(L));
    printf("在表尾删除一个元素后\n");
    DeleteBackList(&L);
    printf("当前表长为%d\n",Length(L));
    int e=0;
    DeleteList(&L,3,&e);
    printf("你删除的元素值为%d\n",e);
    printf("你所查找的值为%d\n",GetElem(L,3));
    printf("你查找的值位于顺序表中第%d位\n",LocateList(L,2));
    printf("%d\n",IsEmptyList(L));
    UpdateList(&L,1,99);
    printf("修改后的表为\n");
    PrintfList(L);
    printf("当前表的最大存储容量为%d\n",L.listSize);
    DestroyList(&L);
    printf("销毁表后\n");
    printf("当前表长为%d\n",Length(L));
    printf("当前表的最大存储容量为%d\n",L.listSize);
    printf("%d\n",IsEmptyList(L));
    //测试顺序表的合并
    // SqList A,B,C;
    // InitList(&A);
    // InitList(&B);
    // InitList(&C);
    // PushBackList(&A,1);
    // PushBackList(&A,2);
    // PushBackList(&A,2);
    // PushBackList(&A,3);
    // PushBackList(&A,6);
    // PushBackList(&A,7);
    // PushBackList(&A,10);
    // PushBackList(&B,2);
    // PushBackList(&B,3);
    // PushBackList(&B,3);
    // PushBackList(&B,5);
    // PushBackList(&B,9);
    // MergeList(A,B,&C);
    // PrintfList(C);
}
//初始化一个空顺序表 
Status InitList(SqList *L)
{
    L->data=(int *)malloc(listInitSize*sizeof(int));
    if (!L->data) exit(OVERFLOW);//分配空间失败就退出
	L->length=0;//空表的长度为0
    L->listSize=listInitSize;//初始存储容量
    return OK;
}
//销毁一个顺序表 
Status DestroyList(SqList *L)
{
    if (L==NULL) exit(OVERFLOW);
    free(L->data);//释放动态开辟的空间
    //将L的属性全部置空
    L->data=NULL;
    L->length=0;
    L->listSize=0;
    return OK;
}
//清空表
Status ClearList(SqList *L){
    //清空表的的前提是表要存在
    if (!L->data) exit(OVERFLOW);
    //只需将顺序表的长度设为0即可
    L->length = 0;
    return OK;
}
//判断顺序表是否为空
Status IsEmptyList(SqList L){
    //只需判断顺序表的长度是否为0
    if (L.length) return FALSE;
    return TRUE;  
}
//求当前线性表的长度
int Length(SqList L){
    return L.length;
}
//检查存储容量是否足够，不够的话要增加
void CheckBase(SqList *L){
    if (L->length>=L->listSize)
    {
        //将数据储存在p中
        int *p=L->data;
        L->data=(int *)malloc((L->listSize+listAddSize)*sizeof(int));
        if (!L->data) exit(OVERFLOW);//分配空间失败就退出
        //把原数据复制到新分配的空间里
        for (int i = 0; i < L->length; i++)
        {
            L->data[i]=p[i];
        }
        L->listSize+=listAddSize;//存储容量增加
    }
}
//在第i个元素之前插入一个元素e
Status InsertList(SqList *L,int i,int e){
    //判断i是否合法
    if(i<1||i>L->length+1) return ERROR;
    //判断存储容量是否足够，不够的话要增加
    CheckBase(L);
    for (int j=L->length; j>=i; j--)
    {
        L->data[j]=L->data[j-1];//把所有i及i后面的元素向后移动一个位置
    }
    L->data[i-1]=e;//插入e
    L->length++;//插入元素后，表长加一
    return OK;
}
//删除表中第i个元素
Status DeleteList(SqList *L,int i,int *e){
    //判断i是否合法
    if(i<1||i>L->length+1) return ERROR;
    *e=L->data[i-1];//将删掉的元素给e返回
    for (i; i<L->length; i++)
    {
        //把所有i及i后面的元素向前移动一个位置
        L->data[i-1]=L->data[i];
    }
    L->length--;
    return OK;
}
//修改表中第i个元素为e
Status UpdateList(SqList *L,int i,int e){
    //判断i是否合法
    if(i<1||i>L->length+1) return ERROR;
    L->data[i-1]=e;
    return OK;
}
//打印顺序表的元素
void PrintfList(SqList L){
    for (int i = 0; i<L.length; i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
}
//尾插元素e
Status PushBackList(SqList *L,int e){
    //判断存储容量是否足够，不够的话要增加
    CheckBase(L);
    L->data[L->length]=e;
    L->length++;
    return OK;
}
//尾删元素
Status DeleteBackList(SqList *L){
    //判断顺序表是否为空
    if (!L->length) return INFEASIBLE;
   //只需将有效个数长度减一即可
    L->length--;
    return OK;
}
//按值查找,返回值为顺序表中的第几个元素
int LocateList(SqList L,int e){
    //判断顺序表是否为空
    if(IsEmptyList(L)) exit(INFEASIBLE);
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i]==e) return i+1;
    }
    return INFEASIBLE;
}
//按位查找,查找顺序表中第i位元素，返回值为查找元素的值
int GetElem(SqList L,int i){
    //判断i是否合法
    if(i<1||i>L.length+1) return INFEASIBLE;
    return L.data[i-1];
}
//合并两个顺序表,将顺序表A和顺序表B合并为顺序表C
void MergeList(SqList A,SqList B,SqList *C){
    int *pa=A.data;
    int *pb=B.data;
    //给合并后的C赋值相应的属性
    C->length=A.length+B.length;
    C->listSize=A.listSize+B.listSize;
    C->data=(int *)malloc(C->listSize*sizeof(int));
    if (!C->data) exit(OVERFLOW);//分配空间失败
    int i=0,j=0,k=0;//i指向顺序表A，j指向顺序表B，k指向顺序表C
    while (i<A.length && j<B.length)
    {
        if (A.data[i]<=B.data[j])
        {
            C->data[k]=A.data[i];
            k++;
            i++;
        }
        else
        {
            C->data[k]=B.data[j];
            k++;
            j++;
        }
    }
    //插入A剩余元素
    while (i<A.length)
    {
        C->data[k]=A.data[i];
        k++;
        i++;
    }
    //插入B剩余元素
    while (j<B.length)
    {
        C->data[k]=B.data[j];
        k++;
        j++;
    }
}
