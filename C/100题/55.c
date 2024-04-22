/*找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能
没有鞍点*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=0;
    printf("请输入矩阵的行数:");
    scanf("%d",&n);
    // 使用malloc函数动态分配内存
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
    
    //判断是否有鞍点
    int flag=0;
    for (int i = 0; i < n; i++){
        //最大值
        int max=0;
        //一列中最小值的行号和一行中最大值的列号
        int row=0,column=0;
        //遍历第i行的所有元素，求得i行中最大的那个，并记录此元素的列号
        for (int j = 0; j < n; j++){
            if (arr[i][j]>=max)
            {
                max=arr[i][j];
                column=j;
            }
        }
        //最小值
        int min=max;
        //遍历第column列的所有元素，求得这列中最小的那个，并记录此元素的行号
        for (int k = 0; k < n; k++)
        {
            if (arr[k][column]<=min)
            {
                min=arr[k][column];
                row=k;
            }
        }
        //如果这个元素的行号等于i，就证明有鞍点
        if (row==i)
        {
            //存在鞍点
            flag=1;
            printf("鞍点为arr[%d][%d]=%d",row,column,arr[row][column]);
        }
    }
    //不存在鞍点
    if (flag==0)
    {
        printf("此矩阵无鞍点\n");
    }
    return 0;
}