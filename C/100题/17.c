/* 输出以下图案
*
***
*****
*******
*****
***
*
*/
#include<stdio.h>

int main(){
    int n=7;//代表图案的行数
    int num=-1;//表示每行有多少个*
    for (int i = 1; i <= n; i++)
    {
        if (i<=(n/2+1)){
            //小于中间行*个数时，下一次每行加两个*
                num+=2;
            }
            else
            {
            //大于中间行*个数时，下一次每行减两个*
                num-=2;
            }
            for (int j = 0; j <num; j++)
            {
                printf("*");
            }
        printf("\n");
    }
    return 0;
}