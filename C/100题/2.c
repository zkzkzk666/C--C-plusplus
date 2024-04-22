//输入一个 N*N 矩阵，求矩阵中的最大值，并且输出其位置。
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=0;
    printf("请输入矩阵的行数:");
    scanf("%d",&n);
    // 动态分配内存
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    //输入矩阵
    printf("请输入矩阵的元素:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            scanf("%d",&(arr[i][j]));
        } 
    }
    //打印矩阵
    printf("该矩阵为:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
    //求最大值，并输出位置
    int max=0;
    //a表示矩阵中的行数，b表示矩阵中的列数
    int a,b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (arr[i][j]>=max)
            {
                max=arr[i][j];
                a=i+1;
                b=j+1;
            }
        }
    }
    printf("矩阵中最大值为：%d\n",max);
    printf("最大值的位置处于矩阵第%d行%d列",a,b);
    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}