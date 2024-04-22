/* 输出“魔方阵”，所谓的方阵是指这样的方阵，它的每一行，每一列和对角之和均相等，
例如，三阶魔方阵为 
8 1 6  
3 5 7 
4 9 2  
要求输出 1-n^2的自然数构成魔方阵*/
#include <stdio.h>
#include<stdlib.h>

// 生成奇数阶魔方阵
void generate_magic_square(int n) {
    // 检查阶数是否为奇数
    if (n % 2 == 0) {
        printf("仅支持奇数阶幻方。\n");
        return;
    }
    // 动态分配内存创建n阶魔方阵的矩阵
    int **magicSquare = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        magicSquare[i] = (int *)malloc(n * sizeof(int));
    }
    // 用零初始化矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }
    // 设置1的初始位置在第一行的中上方
    int row = 0;
    int col = n / 2;
    // 用值填充矩阵
    for (int num = 1; num <= n * n; num++) {
        // 如果单元格已经填充，调整位置
        if (magicSquare[row][col] != 0) {
            col = (col - 1 + n) % n;
            row = (row + 2) % n;
        }
        // 将当前值填入矩阵
        magicSquare[row][col] = num;
        // 移动到下一个位置
        col = (col + 1) % n;
        row = (row - 1 + n) % n;
    }
    // 打印生成的魔方阵
    printf("n阶魔方阵（n=%d）：\n", n);
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            printf("%3d ", magicSquare[row][col]);
        }
        printf("\n");
    }
}

int main() {
    //魔方阵的阶数
    int n;
    printf("输入魔方阵的阶数（奇数）：");
    scanf("%d", &n);
    // 调用生成魔方阵的函数
    generate_magic_square(n);
    return 0;
}
