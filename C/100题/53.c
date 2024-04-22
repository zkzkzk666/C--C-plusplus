/* 输出以下杨辉三角（要求输出 10 行）
   1
  1 1
 1 2 1
1 3 2 1
*/
#include<stdio.h>

//图形的行数
#define N 10
int main(){
    //定义一个10x19的数组，全部初始化为0
    int arr[N][2*N-1]={0};
    //遍历整个数组，给数组赋值
    for (int i = 0; i <N; i++)
    {
        //给三角形两边赋值，全部赋值为1
        arr[i][N-1+i]=arr[i][N-1-i]=1;
        //根据杨辉三角的特性赋值
        for (int j = 1; j <2*i-1;j++)
        {
            //当前数等于左上角数加上右上角数
            arr[i][N-1-i+j]=arr[i-1][N-1-i+j-1]+arr[i-1][N-1-i+j+1];
        }
    }
    //遍历打印数组
    for (int i = 0; i <N; i++)
    {
        for (int j = 0; j <2*N-1; j++)
        {
            //把未被赋值的，即值为0的数不输出改为输出空格，被赋值的数进行输出
            if (arr[i][j]!=0)
            {
                //格式化输出，让输出的三角形对称
                printf("%-6d",arr[i][j]);
            }
            else{
                printf("      ");
            }
        }
        printf("\n");
    }
    return 0;
}