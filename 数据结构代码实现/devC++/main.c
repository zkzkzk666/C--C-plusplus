#include<stdio.h>

int main(){
    int n=0;
    printf("请输入矩阵的行数:");
    scanf("%d",&n);
    int arr[n][n];
    //输入矩阵
    printf("请输入矩阵的元素:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            scanf("%d",&(arr[i][j]));
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
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
    //逆置矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        } 
    }
    //打印矩阵
    printf("逆置后矩阵为:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%d ",arr[i][j]);
        } 
        printf("\n");
    }
    return 0;
}
