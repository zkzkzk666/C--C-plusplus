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

//采用动态分配的顺序存储结构
typedef int* Triplet;
//构造三元组T，并赋值
Status InitTriplet(Triplet *T,int v1,int v2,int v3){
    *T=(int *)malloc(3*sizeof(int));
    if (!T) exit(OVERFLOW);//分配空间失败
    (*T)[0]=v1;
    (*T)[1]=v2;
    (*T)[2]=v3;
    return OK;
}
//销毁三元组T
Status DestroyTriplet(Triplet *T){
    free(*T);//释放动态分配的空间
    T=NULL;
    return OK;
}
//获取三元组中第i个元素
Status Get(Triplet T,int i,int* e){
    if (i<1||i>3) return ERROR;
    *e=T[i-1];
    return OK;
}
//设置三元组中第i个元素为e
Status Put(Triplet *T,int i,int e){
    if (i<1||i>3) return ERROR;
    (*T)[i-1]=e;
    return OK;
}
//判断T中三个元素是否按照升序排列
Status IsAscending(Triplet T){
    return (T[0]<=T[1])&&(T[1]<=T[2]);
}
//判断T中三个元素是否按照降序排列
Status IsDescending(Triplet T){
    return (T[0]>=T[1])&&(T[1]>=T[2]);
}
//用e返回T中最大的元素的值
Status Max(Triplet T,int *e){
    //三元运算符中嵌套三元运算符
    *e=(T[0]>=T[1])?((T[0]>=T[2])?T[0]:T[2]):((T[1]>=T[2])?T[1]:T[2]);
    return OK;
}
//用e返回T中最小的元素的值
Status Min(Triplet T,int *e){
    *e=(T[0]<=T[1])?((T[0]<=T[2])?T[0]:T[2]):((T[1]<=T[2])?T[1]:T[2]);
    return OK;
}
int main(){
    Triplet T;//
    int e,e1=1,e2=2,e3=3;
    InitTriplet(&T,e1,e2,e3);
    Min(T,&e);
    printf("%d\n",e);
    int a=DestroyTriplet(&T);
    printf("%d",a);
    return 0;
}



