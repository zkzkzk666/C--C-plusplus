/* 输出以下图案：
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
    int num1=-1;//表示每行有多少个*
    int num2=4;//表示每行有多少个 （空格）
    for (int i = 1; i <= n; i++)
    {
        if (i<=(n/2+1)){
            //小于中间行*个数时，下一次每行加两个*
                num1+=2;
                num2--;
            }
            else
            {
            //大于中间行*个数时，下一次每行减两个*
                num1-=2;
                num2++;
            }
            for (int k = 0; k < num2; k++)
            {
                printf(" ");
            }
            
            for (int j = 0; j <num1; j++)
            {
                printf("*");
            }
        printf("\n");
    }
    return 0;
}