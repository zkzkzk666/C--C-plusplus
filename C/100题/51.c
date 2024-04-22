// 求 3*3 矩阵对角线之和
#include<stdio.h>

int main()
{
    int n=3;
    int arr[3][3];
    // 输入矩阵
    printf("请输入矩阵的元素:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int sum=arr[0][0]+arr[1][1]+arr[2][2];
    
    // 打印矩阵
    printf("该矩阵为:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("该矩阵主对角线元素之和为：%d",sum);
    return 0;
}
