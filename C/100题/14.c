/*一个数如果恰好等于它的因子之和，这个数就称为完数。找出 1000 内的所有完数。例
如：6=1+2+3。*/ 
#include<stdio.h>

int main(){
    //双重循环求因子
    for (int i = 1; i < 1000; i++)
    {
        int num=0;//记num为所有因子的和
        for (int j = 1; j <=(i/2); j++)
        {
            //当取模为0是是该数的因子
            if ((i%j)==0)
            {
                num+=j;
            }
        }
        //相等时该数为完数
        if (num==i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}