//输入一个 N*N 矩阵，并将矩阵转置输出
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0;
    printf("请输入矩阵的行数:");
    scanf("%d",&n);
    //C语言不允许对数组的大小作动态定义
    // int arr[n][n];直接定义是错误的
    // 要使用malloc函数动态分配内存
    int **arr = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    // 输入矩阵
    printf("请输入矩阵的元素:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    // 打印矩阵
    printf("该矩阵为:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // 逆置矩阵
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    // 打印逆置后的矩阵
    printf("逆置后矩阵为:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // 释放动态分配的内存
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
