/* 输出以下图案
* * * * * 
  * * * * * 
    * * * * * 
      * * * * * 
        * * * * *
*/
#include<stdio.h>

int main(){
    //图案的行数
    int n=5;
    for (int i = 0; i < n; i++)
    {
        //每一行开头空格的个数
        for (int j = 0; j < i; j++)
        {
            printf("  ");
        }
        //*后跟着一个 (空格)
        for (int k = 0; k < n; k++)
        {
            printf("*");
            printf(" ");
        }
        //一行结束后要换行
        printf("\n");
    }
    return 0;
}