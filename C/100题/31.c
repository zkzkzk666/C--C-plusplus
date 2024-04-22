/*编一程序显示由符号组成的三角形图案，行数与图形均可自行输入改变。
   *
  ***
 *****
*******
*/
#include<stdio.h>

int main(){
    //n表示图案的行数
    int n;
    printf("请输入图案的行数:");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        //每行的空格数
        for (int j = n-i; j >0; j--)
        {
            printf(" ");
        }
        //每行的*数
        for (int k = 1; k <= 2*i-1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}