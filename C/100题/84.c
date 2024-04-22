// 输出9*9口诀
#include<stdio.h>

int main(){
    //i代表九行
    for (int i = 1; i < 10; i++)
    {
        //j代表每行有几列
        for (int j = 1; j <=i; j++)
        {
            printf("%d*%d=%d ",j,i,i*j);
        }
        printf("\n");
    }
    return 0;
}